#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "codeGenerator.h"
#include "../AST/AST.h"
#include "../SymbolTable/symbolTable.h"
#include "../SymanticAnalyzer/symanticAnalyzer.h"

FILE* C_src = NULL;
ASTnode_t *exprRoot = NULL, *exprCurr = NULL;
char finalExpr[500];

void openSrcFile(void){    
    if(C_src == NULL){
        C_src = fopen("C_src.c", "a+");
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
        C_src = fopen("C_src.c", "w");
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

char* codeGen_codition(char* lval, char* rval, char* op){
    //printf("generating code for condition: %s %s %s\n", lval, op, rval);
    char* condition = malloc(sizeof(char) * 100);
    
    if(strcmp(op, "!") == 0){
        sprintf(condition, "%s %s", op, lval);
        return condition;
    }

    sprintf(condition, "%s %s %s", lval, op, rval);
    return condition;
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
    clearTree(exprRoot);
    strcpy(finalExpr, "");
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
            fprintf(C_src, "= 0;\n");
        break;
        case SENTENCE:
            //printf("generating code for init: sentence\n");
            fprintf(C_src, "= strdup(\"\");\n");
        break;
        case CHAR:
            //printf("generating code for init: char\n");
            fprintf(C_src, "= '\\0';\n");
        break;
        case WORD:
            //printf("generating code for init: word\n");
            fprintf(C_src, "= strdup(\"\");\n");
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
            fprintf(C_src, "= %s;\n", expression);
        break;
        case SENTENCE:
            fprintf(C_src, "= strdup(%s);\n", expression);
        break;
        case CHAR:
            fprintf(C_src, "= (%s)[0];\n", expression);
        break;
        case WORD:
            fprintf(C_src, "= strdup(%s);\n", expression);
        break;
    }
    closeSrcFile();
    clearTree(exprRoot);
    strcpy(finalExpr, "");
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
        if(getDataType(root->left->token) == INT && getDataType(root->right->token) == INT){
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
}

void codeGen_else(void){
    openSrcFile();
    //printf("generating code for else\n");
    fprintf(C_src, "else\n");
    closeSrcFile();
}

void codeGen_while(char* condition){
    openSrcFile();
    //printf("generating code for while: %s\n", condition);
    fprintf(C_src, "while(%s){\n\t", condition);
    closeSrcFile();
    clearTree(exprRoot);
    strcpy(finalExpr, "");
}

void codeGen_loop(char* id){
    openSrcFile();
    //printf("generating code for loop: %s\n", id);
    fprintf(C_src, "for(int FoorLoopInterator = 0; FoorLoopInterator < %s; FoorLoopInterator++){\n\t", id);
    closeSrcFile();
    clearTree(exprRoot);
    strcpy(finalExpr, "");
}

void codeGen_helpersPrototypes(void){
    openSrcFile();
    //printf("generating code for helper prototypes\n");

    fprintf(C_src, "typedef enum types{\n");
    fprintf(C_src, "INT,\n");
    fprintf(C_src, "WORD,\n");
    fprintf(C_src, "SENTENCE,\n");
    fprintf(C_src, "CHAR,\n");
    fprintf(C_src, "EMPTY\n");
    fprintf(C_src, "}DataType_t;\n");
    closeSrcFile();

    openSrcFile();
    fprintf(C_src, "int getSum(int a, int b);\n");
    fprintf(C_src, "int getSub(int a, int b);\n");
    fprintf(C_src, "char* getConcat(char* a, char* b);\n");
    fprintf(C_src, "char* strRemove(char* str1, char* str2);\n");
    fprintf(C_src, "char* strGetIndex(char* str, int index);\n");
    fprintf(C_src," char charRemove(char ch1, char ch2);\n");
    fprintf(C_src, "char* stringCharRemove(char* str1, char ch);\n");
    closeSrcFile();
}

void codeGen_helpersImplementations(void){
    openSrcFile();
    //printf("generating code for helper implementations\n");
    // addition
    fprintf(C_src, "int getSum(int a, int b){\n");
    fprintf(C_src, "return a + b;\n");
    fprintf(C_src, "}\n");
    closeSrcFile();
    // subtraction
    openSrcFile();
    fprintf(C_src, "int getSub(int a, int b){\n");
    fprintf(C_src, "return a - b;\n");
    fprintf(C_src, "}\n");
    closeSrcFile();
    // concatenation
    openSrcFile();
    fprintf(C_src, "char* getConcat(char* a, char* b){\n");
    fprintf(C_src, "char* result = malloc(sizeof(char) * 100);\n");
    fprintf(C_src, "strcpy(result, a);\n");
    fprintf(C_src, "strcat(result, \" \");\n");
    fprintf(C_src, "strcat(result, b);\n");
    closeSrcFile();
    // if the result contains a new line char, move it the the end of the string
    openSrcFile();
    fprintf(C_src, "if(strchr(result, '\\n') != NULL){\n");
    fprintf(C_src, "char* p = strchr(result, '\\n');\n");
    fprintf(C_src, "int indx = p - result;\n");
    fprintf(C_src, "memmove(result + indx, result + indx + 1, strlen(result) - indx);\n");
    fprintf(C_src, "}\n");
    fprintf(C_src, "return result;\n");
    fprintf(C_src, "}\n");
    closeSrcFile();
    // remove
    openSrcFile();
    fprintf(C_src," char charRemove(char ch1, char ch2) {\n");
    fprintf(C_src," if (ch1 == ch2) {\n");
    fprintf(C_src,"    return '\\0'; // Return null character to indicate removal\n");
    fprintf(C_src,"} else {\n");
    fprintf(C_src,"    return ch1;\n");
    fprintf(C_src,"}\n");
    fprintf(C_src,"}\n");
    fprintf(C_src, "char* strRemove(char* str1, char* str2) {\n");
    fprintf(C_src, "    char* result = malloc(sizeof(char) * 100);\n");
    fprintf(C_src, "    char* p = strstr(str1, str2);\n");
    fprintf(C_src, "    if (p != NULL) {\n");
    fprintf(C_src, "        size_t len2 = strlen(str2);\n");
    fprintf(C_src, "        size_t index = p - str1;\n");
    fprintf(C_src, "        strncpy(result, str1, index);\n");
    fprintf(C_src, "        result[index] = '\\0';\n");
    fprintf(C_src, "        strcat(result, p + len2);\n");
    fprintf(C_src, "    } else {\n");
    fprintf(C_src, "        strcpy(result, str1);\n");
    fprintf(C_src, "    }\n");
    fprintf(C_src, "    return result;\n");
    fprintf(C_src, "}\n");
    fprintf(C_src, "char* stringCharRemove(char* str1, char ch) {\n");
    fprintf(C_src, "char* result = malloc(sizeof(char) * 100);\n");
    fprintf(C_src, "char str2[2];\n");
    fprintf(C_src, "str2[0] = ch;\n");
    fprintf(C_src, "str2[1] = '\\0';\n");
    fprintf(C_src, "char* p = strchr(str1, ch);\n");
    fprintf(C_src, "if (p != NULL) {\n");
    fprintf(C_src, "    size_t index = p - str1;\n");
    fprintf(C_src, "    strncpy(result, str1, index);\n");
    fprintf(C_src, "    result[index] = '\\0';\n");
    fprintf(C_src, "    strcat(result, p + 1);\n");
    fprintf(C_src, "} else {\n");
    fprintf(C_src, "strcpy(result, str1);\n");
    fprintf(C_src, "}\n");
    fprintf(C_src, "return result;\n");
    fprintf(C_src, "}\n");
    closeSrcFile();
    openSrcFile();
    fprintf(C_src, "char* strGetIndex(char* str, int index) {\n");
    fprintf(C_src, "    if (strchr(str, '\\n') != NULL) {\n");
    fprintf(C_src, "        char* copy = malloc(sizeof(char) * 100);\n");
    fprintf(C_src, "        strcpy(copy, str);\n");
    fprintf(C_src, "        char* result = malloc(sizeof(char) * 100);\n");
    fprintf(C_src, "        int i = 0;\n");
    fprintf(C_src, "        if (index < 0) {\n");
    fprintf(C_src, "            // Count the number of tokens\n");
    fprintf(C_src, "            char* token = malloc(sizeof(char) * 100);\n");
    fprintf(C_src, "            token = strtok(copy, \" \\n\");\n");
    fprintf(C_src, "            for (i = 0; token != NULL; i++) {\n");
    fprintf(C_src, "                token = strtok(NULL, \" \\n\");\n");
    fprintf(C_src, "            }\n");
    fprintf(C_src, "            i = i - index;\n");
    fprintf(C_src, "        }\n");
    fprintf(C_src, "        char* token = malloc(sizeof(char) * 100);\n");
    fprintf(C_src, "        token = strtok(copy, \" \\n\");\n");
    fprintf(C_src, "        while (token != NULL) {\n");
    fprintf(C_src, "            if (i == index) {\n");
    fprintf(C_src, "                result = malloc(sizeof(char) * strlen(token) + 1);\n");
    fprintf(C_src, "                strcpy(result, token);\n");
    fprintf(C_src, "                return result;\n");
    fprintf(C_src, "            }\n");
    fprintf(C_src, "            token = strtok(NULL, \" \\n\");\n");
    fprintf(C_src, "            i++;\n");
    fprintf(C_src, "        }\n");
    fprintf(C_src, "    } else {\n");
    fprintf(C_src, "        char* result = malloc(sizeof(char) * 2);\n");
    fprintf(C_src, "        if(index < 0){\n");
    fprintf(C_src, "            index = strlen(str) + index;\n");
    fprintf(C_src, "        }\n");
    fprintf(C_src, "        result[0] = str[index];\n");
    fprintf(C_src, "        result[1] = '\\0';\n");
    fprintf(C_src, "        return result;\n");
    fprintf(C_src, "    }\n");
    fprintf(C_src, "    return \"\\0\";\n");
    fprintf(C_src, "}\n");
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
        fprintf(C_src, "{\n");
        break;
    case '}':
        fprintf(C_src, "}\n");
        break;
    }
    closeSrcFile();
}