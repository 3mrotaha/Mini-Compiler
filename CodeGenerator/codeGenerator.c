#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "codeGenerator.h"
#include "../AST/AST.h"
#include "../SymbolTable/symbolTable.h"
#include "../SymanticAnalyzer/symanticAnalyzer.h"

char outputFile[50] = {0};
FILE* C_src = NULL;
ASTnode_t *exprRoot = NULL, *exprCurr = NULL;
char finalExpr[500];

void openSrcFile(void){    
    if(C_src == NULL){
        C_src = fopen(outputFile, "a+");
        if(C_src == NULL){
            //printf("Error: Couldn't open file C_src.c\n");
            exit(1);
        }
    }
}

void closeSrcFile(void){
    if(C_src != NULL){
        fclose(C_src);
        C_src = NULL;
    }
}

void addExprNode(char* value, ASTnode_t* left, ASTnode_t* right){
    //printf("creating expr node: %s\n", value);
    if(exprRoot == NULL){
        exprRoot = malloc(sizeof(ASTnode_t));
        exprRoot->token = value;
        exprRoot->left = left;
        exprRoot->right = right;
        exprCurr = exprRoot;
    }
    else{
        ASTnode_t* newNode = malloc(sizeof(ASTnode_t));
        newNode->token = value;
        newNode->left = left;
        newNode->right = right;
        if(exprCurr->left == NULL){
            exprCurr->left = newNode;
        }
        else if(exprCurr->right == NULL){
            exprCurr->right = newNode;
        }
        else{
            exprCurr = exprCurr->left;
            exprCurr->left = newNode;
        }
    }
}

void clearTree(ASTnode_t* root){
    //printf("clearing tree\n");
    if(root == NULL){
        return;
    }
    clearTree(root->left);
    clearTree(root->right);
    free(root);
    root = NULL;
}

void codeGen_Init(void){
    if(C_src == NULL){
        C_src = fopen(outputFile, "w");
        if(C_src == NULL){
            //printf("Error: Couldn't open file C_src.c\n");
            exit(1);
        }
    }
    //printf("initializing code generator\n");
    
    fprintf(C_src, "#include <stdio.h>\n");
    fprintf(C_src, "#include <stdlib.h>\n");
    fprintf(C_src, "#include <string.h>\n");
    fprintf(C_src, "#include <stdbool.h>\n");
    fprintf(C_src, "#include <ctype.h>\n");
    fprintf(C_src, "#include <math.h>\n");
    closeSrcFile();
    codeGen_helpersPrototypes();
    codeGen_helpersImplementations();
    openSrcFile();
    fprintf(C_src, "int main(void){\n");
    closeSrcFile();
}

void codeGen_Close(void){
    openSrcFile();
    //printf("closing code generator\n");
    fprintf(C_src, "return 0;\n");
    fprintf(C_src, "}\n");
    closeSrcFile();
}

void codeGen_id(char* id){
    //printf("generating code for id: %s\n", id);
    openSrcFile();
    fprintf(C_src, "%s", id);
    closeSrcFile();
}

void codeGen_clearWorkTree(void){
    //printf("clearing work tree\n");
    clearTree(exprRoot);    
    strcpy(finalExpr, "");
    exprRoot = NULL;
}

char* codeGen_condition(char *expr1, DataType_t dt1, char *expr2, DataType_t dt2, char* op){        
    if(expr2 != NULL){
        if(dt1 == WORD && dt1 == WORD){
            sprintf(finalExpr, "strcmp(%s, %s) %s 0", expr1, expr2, op);
            // if(strcmp(op, "<") == 0){
            //     sprintf(finalExpr, "strcmp(%s, %s) < 0", expr1);
            // }
            // else if(strcmp(op, ">") == 0){
            //     sprintf(finalExpr, "strcmp(%s, %s) > 0", expr1);
            // }
            // else if(strcmp(op, "<=") == 0){
            //     sprintf(finalExpr, "strcmp(%s, %s) <= 0", expr1);
            // }
            // else if(strcmp(op, ">=") == 0){
            //     sprintf(finalExpr, "strcmp(%s, %s) >= 0", expr1);
            // }
            // else if(strcmp(op, "==") == 0){
            //     sprintf(finalExpr, "strcmp(%s, %s) == 0", expr1);
            // }
            // else if(strcmp(op, "!=") == 0){
            //     sprintf(finalExpr, "strcmp(%s, %s) != 0", expr1);
            // }
            return finalExpr;
        }else if(dt1 == SENTENCE && dt1 == SENTENCE){
            sprintf(finalExpr, "strcmp(%s, %s) %s 0", expr1, expr2, op);
            // if(strcmp(op, "<") == 0){
            // }
            // else if(strcmp(op, ">") == 0){
            //     sprintf(finalExpr, "%s > 0", expr1);
            // }
            // else if(strcmp(op, "<=") == 0){
            //     sprintf(finalExpr, "%s <= 0", expr1);
            // }
            // else if(strcmp(op, ">=") == 0){
            //     sprintf(finalExpr, "%s >= 0", expr1);
            // }
            // else if(strcmp(op, "==") == 0){
            //     sprintf(finalExpr, "%s == 0", expr1);
            // }
            // else if(strcmp(op, "!=") == 0){
            //     sprintf(finalExpr, "%s != 0", expr1);
            // }
            return finalExpr;
        }else{
            if(dt1 == CHAR && dt2 == CHAR)
                sprintf(finalExpr, "(%s)[0] %s (%s)[0]", expr1, op, expr2);
            else
                sprintf(finalExpr, "%s %s %s", expr1, op, expr2);

            return finalExpr;
        }
    }
    else{
        if(dt1 == WORD || dt1 == SENTENCE || dt1 == CHAR){
            sprintf(finalExpr, "(%s)[0]", expr1);
        }
        return finalExpr;
    }
}

void codeGen_input(char* prompt_val, char* id, DataType_t type){
    openSrcFile();
    //printf("generating code for input: %s %s %d\n", prompt_val, id, type);
    fprintf(C_src, "printf(%s);\n", prompt_val);
    switch(type){
        case INT:
            fprintf(C_src, "scanf(\"%%d\", &%s);\n", id);
        break;
        case SENTENCE:
            fprintf(C_src, "scanf(\"%%[^\\n]s\", %s);\n", id);
        break;
        case CHAR:
            fprintf(C_src, "scanf(\"%%c\", &%s);\n", id);
        break;
        case WORD:
            fprintf(C_src, "scanf(\"%%s\", %s);\n", id);
        break;
    }
    closeSrcFile();
}

void codeGen_output(char* expression){    
    openSrcFile();
    //printf("generating code for output: %s\n", expression);
    fprintf(C_src, "printf(\"%%s\", %s);\n", expression);
    closeSrcFile();
    codeGen_clearWorkTree();
}

void codeGen_declare(char* id, DataType_t type){
    openSrcFile();
    //printf("generating code for declare: %s %d", id, type);
    switch(type){
        case INT:
            fprintf(C_src, "int %s", id);
        break;
        case SENTENCE:
            fprintf(C_src, "char *%s", id);
        break;
        case CHAR:
            fprintf(C_src, "char %s", id);
        break;
        case WORD:
            fprintf(C_src, "char *%s", id);
        break;
    }
    closeSrcFile();
}

void codeGen_initVar(DataType_t type){
    // initialize the rval
    openSrcFile();
    switch (type)
    {
        case INT:
            //printf("generating code for init: int\n");
            fprintf(C_src, "= 0");
        break;
        case SENTENCE:
            //printf("generating code for init: sentence\n");
            fprintf(C_src, "= strdup(\"\\n\")");
        break;
        case CHAR:
            //printf("generating code for init: char\n");
            fprintf(C_src, "= '\\0'");
        break;
        case WORD:
            //printf("generating code for init: word\n");
            fprintf(C_src, "= strdup(\"\")");
        break;
    }
    closeSrcFile();
}

void codeGen_assign(char* expression, DataType_t type){
    openSrcFile();
    //printf("generating code for assign: %s\n", expression);
    switch (type)
    {
        case INT:
            fprintf(C_src, "= %s", expression);
        break;
        case SENTENCE:
            fprintf(C_src, "= strdup(%s)", expression);
        break;
        case CHAR:
            fprintf(C_src, "= (%s)[0]", expression);
        break;
        case WORD:
            fprintf(C_src, "= strdup(%s)", expression);
        break;
    }
    closeSrcFile();
    codeGen_clearWorkTree();
}

void writeExpressionTreeToFile(ASTnode_t* root, FILE* file, int level) {
    if (root == NULL) {
        return;
    }

    // Write the current node to the file
    for (int i = 0; i < level; i++) {
        fprintf(file, "    "); // Indentation based on the level of the node
    }
    fprintf(file, "%s\n", root->token);

    // Traverse the left sub-tree
    writeExpressionTreeToFile(root->left, file, level + 1);

    // Traverse the right sub-tree
    writeExpressionTreeToFile(root->right, file, level + 1);
}

char* codeGen_expression(ASTnode_t *root){
    if(root == NULL){
        return finalExpr;
    }

    //printf("generating code for expression: %s\n", root->token);
    if(strcmp(root->token, "+") == 0){
        strcat(finalExpr, "getSum(");
    }
    else if(strcmp(root->token, "-") == 0){
        if(getDataType(root->left->token) == INT || getDataType(root->right->token) == INT){
            strcat(finalExpr, "getSub(");
        }
        else{
            // if word word, sentence word, sentence sentence
            strcat(finalExpr, "strRemove(");
        }
    }
    else if(strcmp(root->token, "#") == 0){
        strcat(finalExpr, "getConcat(");
    }
    else if(strcmp(root->token, ":") == 0){
        strcat(finalExpr, "strGetIndex(");
    }
    else if(strcmp(root->token, "<") == 0){
        strcat(finalExpr, "getLessThan(");
    }
    else if(strcmp(root->token, ">") == 0){
        strcat(finalExpr, "getGreaterThan(");
    }
    else if(strcmp(root->token, "<=") == 0){
        strcat(finalExpr, "getLessThanOrEqual(");
    }
    else if(strcmp(root->token, ">=") == 0){
        strcat(finalExpr, "getGreaterThanOrEqual(");
    }
    else if(strcmp(root->token, "==") == 0){
        strcat(finalExpr, "getEqual(");
    }
    else if(strcmp(root->token, "!=") == 0){
        strcat(finalExpr, "getNotEqual(");
    }
    else{
        if(getDataType(root->token) == CHAR){
            strcat(finalExpr, "(char[2]){");
            strcat(finalExpr, root->token);
            strcat(finalExpr, ", '\\0'}");
        }
        else{
            strcat(finalExpr, root->token);
        }
    }
    codeGen_expression(root->left);    
    if(root->left != NULL)
        strcat(finalExpr, ",");
    else{
        return finalExpr;
    }
    codeGen_expression(root->right);
    strcat(finalExpr, ")");    
    return finalExpr;
}


void codeGen_if(char* condition){
    openSrcFile();
    //printf("generating code for if: %s\n", condition);
    fprintf(C_src, "if(%s)\n", condition);
    closeSrcFile();
    codeGen_clearWorkTree();
}

void codeGen_else(void){
    openSrcFile();
    //printf("generating code for else\n");
    fprintf(C_src, "else\n");
    closeSrcFile();
    codeGen_clearWorkTree();
}

void codeGen_while(char* condition){    
    openSrcFile();
    //printf("generating code for while: %s\n", condition);
    fprintf(C_src, "while(%s){\n\t", condition);
    closeSrcFile();
    codeGen_clearWorkTree();
}

void codeGen_loop(char* id){
    openSrcFile();
    //printf("generating code for loop: %s\n", id);
    fprintf(C_src, "for(int FoorLoopInterator = 0; FoorLoopInterator < %s; FoorLoopInterator++){\n\t", id);
    closeSrcFile();
    codeGen_clearWorkTree();
}

void codeGen_helpersPrototypes(void){
    openSrcFile();
    //printf("generating code for helper prototypes\n");

    fprintf(C_src, "typedef enum types{\n");
    fprintf(C_src, "    INT,\n");
    fprintf(C_src, "    WORD,\n");
    fprintf(C_src, "    SENTENCE,\n");
    fprintf(C_src, "    CHAR,\n");
    fprintf(C_src, "    EMPTY\n");
    fprintf(C_src, "}DataType_t;\n");
    closeSrcFile();

    openSrcFile();
    fprintf(C_src, "int getSum(int a, int b);\n");
    fprintf(C_src, "int getSub(int a, int b);\n");
    fprintf(C_src, "char* getConcat(char* a, char* b);\n");
    fprintf(C_src, "char* strRemove(char* str1, char* str2);\n");
    fprintf(C_src, "char* strGetIndex(char* str, int index);\n");
    closeSrcFile();
}

void codeGen_helpersImplementations(void){
    openSrcFile();
    //printf("generating code for helper implementations\n");
    // addition
    fprintf(C_src, "int getSum(int a, int b){\n");
    fprintf(C_src, "    return a + b;\n");
    fprintf(C_src, "}\n");
    closeSrcFile();
    // subtraction
    openSrcFile();
    fprintf(C_src, "int getSub(int a, int b){\n");
    fprintf(C_src, "    return a - b;\n");
    fprintf(C_src, "}\n");
    closeSrcFile();
    // concatenation
    openSrcFile();
    fprintf(C_src, "char* getConcat(char* a, char* b){\n");
    fprintf(C_src, "if(a == NULL){\n");
    fprintf(C_src, "    return b;\n");
    fprintf(C_src, "}\n");
    fprintf(C_src, "if(b == NULL){\n");
    fprintf(C_src, "    return a;\n");
    fprintf(C_src, "}\n");
    fprintf(C_src, "    char* result = calloc(100, sizeof(char));\n");
    fprintf(C_src, "    strcpy(result, a);\n");
    fprintf(C_src, "    if(strlen(a) > 1 && (strlen(b) > 1 || strchr(a, '\\n') != NULL))\n");
    fprintf(C_src, "        strcat(result, \" \");\n");
    fprintf(C_src, "    if(strchr(result, '\\n') != NULL){\n");
    fprintf(C_src, "        strcat(result, b);\n");
    fprintf(C_src, "        while(strchr(result, '\\n') != NULL){\n");
    fprintf(C_src, "            char* p = strchr(result, '\\n');\n");
    fprintf(C_src, "            int indx = p - result;\n");
    fprintf(C_src, "            result[indx] = '\\0';\n");
    fprintf(C_src, "            strcat(result, p + 1);\n");
    fprintf(C_src, "        }\n");
    fprintf(C_src, "        \n");
    fprintf(C_src, "        strcat(result, \"\\n\");\n");
    fprintf(C_src, "    }\n");
    fprintf(C_src, "    else{\n");
    fprintf(C_src, "        strcat(result, b);\n");
    fprintf(C_src, "    }\n");
    fprintf(C_src, "    return result;\n");
    fprintf(C_src, "}\n");
    closeSrcFile();
    // remove
    openSrcFile();
fprintf(C_src, "char* strRemove(char* str1, char* str2) {\n");
fprintf(C_src, "    if(strchr(str1, ' ') != NULL){ // sentence expression\n");
fprintf(C_src, "        // implement using strtok\n");
fprintf(C_src, "        char* copy = calloc(100, sizeof(char));\n");
fprintf(C_src, "        strcpy(copy, str1);\n");
fprintf(C_src, "        char* result = calloc(100, sizeof(char));\n");
fprintf(C_src, "        char* token = calloc(100, sizeof(char));\n");
fprintf(C_src, "        token = strtok(copy, \" \\n\");\n");
fprintf(C_src, "        while(token != NULL){\n");
fprintf(C_src, "            if(strcmp(token, str2) != 0){\n");
fprintf(C_src, "                strcat(result, token);\n");
fprintf(C_src, "                strcat(result, \" \");\n");
fprintf(C_src, "            }\n");
fprintf(C_src, "            token = strtok(NULL, \" \\n\");\n");
fprintf(C_src, "        }\n");
fprintf(C_src, "        strcat(result, \"\\n\");\n");
fprintf(C_src, "        return result;\n");
fprintf(C_src, "    }\n");
fprintf(C_src, "    else{ // word expression        \n");
fprintf(C_src, "        if(strlen(str2) > 1){\n");
fprintf(C_src, "            return strcmp(str1, str2) == 0 ? NULL : str1;\n");
fprintf(C_src, "        }\n");
fprintf(C_src, "        else{\n");
fprintf(C_src, "            char* result = calloc(100, sizeof(char));\n");
fprintf(C_src, "            strcpy(result, str1);\n");
fprintf(C_src, "            char* p = strstr(result, str2);\n");
fprintf(C_src, "            if(p == NULL){\n");
fprintf(C_src, "                return strdup(result);\n");
fprintf(C_src, "            }\n");
fprintf(C_src, "            int indx = p - result;\n");
fprintf(C_src, "            result[indx] = '\\0';\n");
fprintf(C_src, "            strcat(result, p + strlen(str2));\n");
fprintf(C_src, "            return strdup(result);\n");
fprintf(C_src, "        }\n");
fprintf(C_src, "    }\n");
fprintf(C_src, "}\n");
    closeSrcFile();
    openSrcFile();
    fprintf(C_src, "char* strGetIndex(char* str, int index) {\n");
    fprintf(C_src, "    if (strchr(str, '\\n') != NULL) {\n");
    fprintf(C_src, "        char* copy = calloc(100, sizeof(char));\n");
    fprintf(C_src, "        strcpy(copy, str);\n");
    fprintf(C_src, "        char* result = calloc(100, sizeof(char));\n");
    fprintf(C_src, "        int i = 0;\n");
    fprintf(C_src, "        if (index < 0) {\n");
    fprintf(C_src, "            // Count the number of tokens\n");
    fprintf(C_src, "            char* token = calloc(100, sizeof(char));\n");
    fprintf(C_src, "            token = strtok(copy, \" \\n\");\n");
    fprintf(C_src, "            for (i = 0; token != NULL; i++) {\n");
    fprintf(C_src, "                token = strtok(NULL, \" \\n\");\n");
    fprintf(C_src, "            }\n");
    fprintf(C_src, "            index = i + index;\n");
    fprintf(C_src, "            i = 0;\n");
    fprintf(C_src, "        }\n");
    fprintf(C_src, "        char* token = calloc(100, sizeof(char));\n");
    fprintf(C_src, "        strcpy(copy, str);\n");
    fprintf(C_src, "        token = strtok(copy, \" \\n\");\n");
    fprintf(C_src, "        while (token != NULL) {\n");
    fprintf(C_src, "            if (i == index) {\n");
    fprintf(C_src, "                result = calloc(strlen(token) + 1, sizeof(char));\n");
    fprintf(C_src, "                strcpy(result, token);\n");
    fprintf(C_src, "                return result;\n");
    fprintf(C_src, "            }\n");
    fprintf(C_src, "            token = strtok(NULL, \" \\n\");\n");
    fprintf(C_src, "            i++;\n");
    fprintf(C_src, "        }\n");
    fprintf(C_src, "    } else {\n");
    fprintf(C_src, "        char* result =calloc(2, sizeof(char));\n");
    fprintf(C_src, "        if(index < 0){\n");
    fprintf(C_src, "            index = strlen(str) + index;\n");
    fprintf(C_src, "        }\n");
    fprintf(C_src, "        result[0] = str[index];\n");
    fprintf(C_src, "        result[1] = '\\0';\n");
    fprintf(C_src, "        return result;\n");
    fprintf(C_src, "    }\n");
    fprintf(C_src, "        return \"\\0\";\n");
    fprintf(C_src, "    }\n");
    closeSrcFile();
}

void codeGen_punc(char* punc){
    openSrcFile();
    //printf("generating code for punc: %s\n", punc);
    switch (*punc)
    {
    case ';':
        fprintf(C_src, ";\n");
        break;
    case ',':
        fprintf(C_src, ", ");
        break;
    case '(':
        fprintf(C_src, "(");
        break;
    case ')':
        fprintf(C_src, ")");
        break;
    case '{':
        fprintf(C_src, "{\n\t");
        break;
    case '}':
        fprintf(C_src, "}\n");
        break;
    case '!':
        fprintf(C_src, "!");
        break;
    }
    closeSrcFile();
}