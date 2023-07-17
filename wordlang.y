%{
#include "SymbolTable\symbolTable.h"
#include "SymanticAnalyzer/symanticAnalyzer.h"
#include "AST\AST.h"
#include "CodeGenerator/codeGenerator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern int yyparse();
extern int yywrap();
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
int yydebug = 1;
FILE* file;
int tempCount = 0;
extern DataType_t dataType;
extern ASTnode_t *root;
extern ASTnode_t *exprRoot;
extern FILE* traverseFile;
char* buff;
void print_sentence(char* sentence);
void storeInSymbolTable(char *name, Type_t type, DataType_t dataType, int lineNo, char* value);
void yyerror(const char* s);

/* Additional function declarations */

%}

%union {
    struct {
        char* name;
        int intVal;
        char charVal;
        char* wordVal;
        DataType_t varType;
        Type_t type;
        ASTnode_t *nd;
    }nodeType;
}

%token <nodeType> CHAR_CONSTANT INT_CONSTANT WORD_CONSTANT SENTENCE_CONSTANT IDENTIFIER 
%token <nodeType> CHAR_TYPE INT_TYPE WORD_TYPE SENTENCE_TYPE
%token <nodeType> INPUT OUTPUT LOOP IF ELSE WHILE TRUE FALSE
%token <nodeType> ADD REMOVE CONCAT GET 
%token <nodeType> LT GT LE GE EQ NE EQUAL NOT COMMA SEMI_COLON OPEN_BRACKET CLOSE_BRACKET OPEN_PAREN CLOSE_PAREN
%type <nodeType> program assignment datatype value expression conditional_statement else_clause if_clause condition loop_statement statement statement_list relop arthop declaration

%start program

%right '(' ')'
%left GET
%left CONCAT
%left ADD REMOVE
%right EQUAL NOT
%left LE GE GT LT EQ NE


%%

program: statement_list {
        //printf("Program is syntactically correct.\n");
        $$.nd = AST_mkNode($1.nd, NULL, "start");
        root = $$.nd;
};

statement_list: statement {
            $$.nd = $1.nd;
        }
        |statement_list statement { 
            $$.nd = AST_mkNode($1.nd, $2.nd, "statement_list");
            //printf("statement_list\n");
        }
;


statement: declaration   { 
                $$.nd = $1.nd;
                //printf("declaration\n");
         }
         | IDENTIFIER {codeGen_id($1.name);} assignment SEMI_COLON {
                //printf("start assignment\n");
                checkDeclaration($1.name);
                $1.varType = getDataType($1.name);
                checkType($1.varType, $3.varType);                
                $1.nd = AST_mkNode(NULL, NULL, $1.name);
                $$.nd = AST_mkNode($1.nd, $3.nd, $1.name);                
         }
         | INPUT SENTENCE_CONSTANT IDENTIFIER SEMI_COLON {         
            checkDeclaration($3.name);
            $2.nd = AST_mkNode(NULL, NULL, $2.name);
            $3.nd = AST_mkNode(NULL, NULL, $3.name);
            $$.nd = AST_mkNode($2.nd, $3.nd, $1.name);
            $3.varType = getDataType($3.name);
            codeGen_input($2.name, $3.name, $3.varType);
            //printf("input\n");
        }
         | OUTPUT expression SEMI_COLON {
            $$.nd = exprRoot = AST_mkNode(NULL, $2.nd, $1.name);
            char* expr = strdup(codeGen_expression(exprRoot->right));
            codeGen_output(expr);
            //printf("output\n");
         }
        | conditional_statement    { 
                $$.nd = $1.nd;
                //printf("conditional_statement\n");
          }
         | loop_statement        { 
                $$.nd = $1.nd;
                //printf("loop_statement\n");
          }
         
;

datatype: CHAR_TYPE { insert_type(yytext); 
                    //printf("char\n");                    
}
        | INT_TYPE  { insert_type(yytext); 
                //printf("int\n");
        }
        | WORD_TYPE { insert_type(yytext); 
                //printf("word\n");
        }
        | SENTENCE_TYPE { insert_type(yytext); 
                //printf("sentence\n");
        }
        ;

declaration: datatype IDENTIFIER SEMI_COLON {
                isValidVarName($2.name);
                checkMultiDeclaration($2.name);
                storeInSymbolTable($2.name, VARIABLE, dataType, yylineno, "");
                $2.varType = dataType;
                $2.nd = AST_mkNode(NULL, NULL, $2.name);
                $$.nd = AST_mkNode($2.nd, NULL, "declaration");
                codeGen_declare($2.name, dataType);
                codeGen_initVar(dataType);
                //printf("declaration without assignment\n");
             }
           | datatype IDENTIFIER {codeGen_declare($2.name, dataType);} assignment SEMI_COLON {
                isValidVarName($2.name);
                checkMultiDeclaration($2.name);
                checkType(dataType, $4.varType);
                storeInSymbolTable($2.name, VARIABLE, dataType, yylineno, "");
                $2.varType = dataType;
                $2.nd = AST_mkNode(NULL, NULL, $2.name);
                $$.nd = AST_mkNode($2.nd, $4.nd, "declaration");
                //printf("declaration with assignment\n");
            }      
           ;


punctuatuion: COMMA { codeGen_punc($1.name);}
            | SEMI_COLON {codeGen_punc($1.name);}
            | OPEN_BRACKET {codeGen_punc($1.name);}
            | CLOSE_BRACKET {codeGen_punc($1.name);}
            | OPEN_PAREN {codeGen_punc($1.name);}
            | CLOSE_PAREN {codeGen_punc($1.name);}
            ;

expression: OPEN_PAREN expression CLOSE_PAREN {                
                $$.varType = $2.varType;
                $$.nd = $2.nd;
            }
            | expression arthop expression  {                                           
                $$.varType = checkExprDataType($1.varType, $3.varType, $2.name);     
                $$.nd = AST_mkNode($1.nd, $3.nd, $2.name);                                
            }
            | value {
                $$.varType = $1.varType;
                $$.nd = $1.nd;
            }
;
          

assignment: EQUAL expression {    
                $$.varType = $2.varType;
                $$.nd = exprRoot = AST_mkNode($1.nd, $2.nd, $1.name);
                char* expr = strdup(codeGen_expression(exprRoot->right));
                codeGen_assign(expr, $2.varType);
};


value: INT_CONSTANT       {        
        storeInSymbolTable($1.name, CONSTANT, INT, yylineno, yytext);
        $$.varType = INT;
        $$.nd = AST_mkNode(NULL, NULL, $1.name);
        $$.name = strdup($1.name);
        //printf("int\n");
    }
     | CHAR_CONSTANT      {
        storeInSymbolTable($1.name, CONSTANT, CHAR, yylineno, yytext);
        $$.varType = CHAR;
        $$.nd = AST_mkNode(NULL, NULL, $1.name);
        $$.name = strdup($1.name);
        //printf("char\n");
    }
     | WORD_CONSTANT      { 
        storeInSymbolTable($1.name, CONSTANT, WORD, yylineno, $1.wordVal);
        $$.varType = WORD;
        $$.nd = AST_mkNode(NULL, NULL, $1.name);
        $$.name = strdup($1.name);
        //printf("word\n");
    }
     | SENTENCE_CONSTANT  {
         printf("sentence\n"); 
         storeInSymbolTable($1.name, CONSTANT, SENTENCE, yylineno, $1.wordVal);
         $$.varType = SENTENCE;
         $$.nd = AST_mkNode(NULL, NULL, $1.name);
         $$.name = strdup($1.name);
    }    
     | IDENTIFIER         {
            checkDeclaration($1.name);
            $$.varType = getDataType($1.name);
            //printf("varType: %d\n", $1.varType);
            $$.nd = AST_mkNode(NULL, NULL, $1.name);
            $$.name = strdup($1.name);
            //printf("identifier\n");
    }
     ;


conditional_statement: if_clause
    | if_clause else_clause
    ;
if_clause: IF OPEN_PAREN condition CLOSE_PAREN {codeGen_if($3.wordVal);} OPEN_BRACKET {codeGen_punc($6.name);} statement_list CLOSE_BRACKET {
        $$.nd = AST_mkNode($3.nd, $8.nd, $1.name);
        codeGen_punc($9.name);
        //printf("if with brackets\n");
     }
    | IF OPEN_PAREN condition CLOSE_PAREN {codeGen_if($3.wordVal);} statement { 
        $$.nd = AST_mkNode($3.nd, $6.nd, $1.name);
        //printf("if\n");
     }
    ;
else_clause: ELSE {codeGen_else();} statement { 
        $$.nd = AST_mkNode(NULL, $3.nd, "else");
        //printf("else\n");
 }
    | ELSE {codeGen_else();} OPEN_BRACKET {codeGen_punc($3.name);} statement_list CLOSE_BRACKET {
        $$.nd = AST_mkNode(NULL, $5.nd, "else");
        codeGen_punc($6.name);
        //printf("else with brackets\n");
     }
    ;

condition: value {
                $$.nd = $1.nd;
                $$.wordVal = $1.name;
                //printf("value-only condition\n");
            }
            | expression relop expression {
                checkType($1.varType, $3.varType);
                $$.varType = INT;
                $$.nd = AST_mkNode($1.nd, $3.nd, $2.name);                
                $$.wordVal = codeGen_codition($1.name, $3.name, $2.name);
                //printf("value relop value condition\n");
            }       
          | NOT condition    {
                checkType($2.varType, INT);
                $$.varType = INT;
                $$.nd = AST_mkNode($1.nd, $2.nd, $1.name);
                $$.wordVal = strdup(codeGen_codition($1.name, $2.wordVal, $1.name));
                //printf("not condition\n");
          }
          | TRUE {
            storeInSymbolTable($1.name, KEYWORD, INT, yylineno, "1");
            $$.varType = INT;
            $$.nd = NULL;
            $$.wordVal = "1";
            //printf("true\n");
          }
          | FALSE {
            storeInSymbolTable($1.name, KEYWORD, INT, yylineno, "0");
            $$.varType = INT;
            $$.nd = NULL;
            $$.wordVal = "0";
            //printf("false\n");
        }
        ;

relop: LE
| GE
| EQ 
| NE
| GT
| LT
| NOT;

arthop: ADD
| CONCAT
| REMOVE
| GET;

loop_statement: LOOP OPEN_PAREN expression CLOSE_PAREN {exprRoot = AST_mkNode(NULL, $3.nd, $3.name);
                    char* expr = strdup(codeGen_expression(exprRoot->right)); codeGen_loop(expr);} OPEN_BRACKET statement_list CLOSE_BRACKET {    
                    $$.nd = AST_mkNode($3.nd, $7.nd, $1.name);                    
                    codeGen_punc($8.name);
                    //printf("loop\n");                    
                }
               | LOOP OPEN_PAREN expression CLOSE_PAREN  {exprRoot = AST_mkNode(NULL, $3.nd, $3.name);
                    char* expr = strdup(codeGen_expression(exprRoot->right)); codeGen_loop(expr);}  statement {                 
                    $$.nd = AST_mkNode($3.nd, $6.nd, $1.name);                    
                    codeGen_punc("}");
                    //printf("loop\n");
                }
               | WHILE OPEN_PAREN condition CLOSE_PAREN {exprRoot = AST_mkNode(NULL, $3.nd, $3.name);
                    char* expr = strdup(codeGen_expression(exprRoot->right)); codeGen_while(expr);} OPEN_BRACKET statement_list CLOSE_BRACKET {
                    $$.nd = AST_mkNode($3.nd, $7.nd, $1.name); 
                    codeGen_punc($8.name);                    
                    //printf("while\n");
                }                
               | WHILE OPEN_PAREN condition {exprRoot = AST_mkNode(NULL, $3.nd, $3.name);
                    char* expr = strdup(codeGen_expression(exprRoot->right)); codeGen_while(expr);} CLOSE_PAREN statement
                { 
                    $$.nd = AST_mkNode($3.nd, $5.nd, $1.name);
                    codeGen_punc("}");                     
                    //printf("while\n");
                }
               ;

%%

void yyerror(const char* s) {
    //printf("at line %d: Error; %s\n", yylineno, s);
    exit(1);
}

int main(int argc, char* argv[]) {
    static int WriteOnce = 0;
    if (argc < 2) {
        //printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE* inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        //printf("Error opening input file.\n");
        return 1;
    }

    yyin = inputFile;
    if(WriteOnce == 0){
        codeGen_Init();
        symbolTable_init();
        WriteOnce++;
    }

    yyparse();
    fclose(inputFile);
    /* print_symbol_table(); */
    /* traverseFile = fopen("traverse.txt", "w+");
    AST_traverse(root, 0);
    fclose(traverseFile); */
    codeGen_Close();
    return 0;
}


/* Helper function definitions */

void storeInSymbolTable(char *name, Type_t type, DataType_t dataType, int lineNo, char* value){
    if(dataType == INT) {
        insert_symbol((symbolTable_t) {.name=strdup(name), .type=type, .dataType=dataType, .lineNo=lineNo, .Value=strdup(value)});
    } else if(dataType == CHAR) {
        char arr[2] = {value[1], '\0'};
        insert_symbol((symbolTable_t) {.name=strdup(name), .type=type, .dataType=dataType, .lineNo=lineNo, .Value=strdup(arr)});
    } else if(dataType == WORD) {
        insert_symbol((symbolTable_t) {.name=strdup(name), .type=type, .dataType=dataType, .lineNo=lineNo, .Value=strdup(value)});
    } else if(dataType == SENTENCE) {
        insert_symbol((symbolTable_t) {.name=strdup(name), .type=type, .dataType=dataType, .lineNo=lineNo, .Value=strdup(value)});
    }
    else{
        insert_symbol((symbolTable_t) {.name=strdup(name), .type=type, .dataType=dataType, .lineNo=lineNo});
    }
}

void print_sentence(char* sentence){
    int i = 0;
    while(sentence[i] != '\n'){
        printf("%c", sentence[i]);
        i++;
    }
}
