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
extern char outputFile[50];
extern DataType_t dataType;
extern ASTnode_t *root;
extern ASTnode_t *exprRoot;
extern FILE* traverseFile;
char condExpr[500] = "";
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
%type <nodeType> program definition assignment datatype value expression conditional_statement else_clause if_clause condition loop_statement statement statement_list relop arthop declaration

%start program

%nonassoc  '(' ')'
%left GET
%left CONCAT
%left ADD REMOVE
%right EQUAL NOT
%left LE GE GT LT EQ NE


%%

program: statement_list {
        $$.nd = AST_mkNode($1.nd, NULL, "start");
        root = $$.nd;
};

statement_list: statement {
            $$.nd = $1.nd;
        }
        |statement_list statement { 
            $$.nd = AST_mkNode($1.nd, $2.nd, "statement_list");
        }
;


statement: declaration   { 
                $$.nd = $1.nd;
         }
         | IDENTIFIER {codeGen_idAssign($1.name);} assignment SEMI_COLON {
                checkDeclaration($1.name);
                $1.varType = getDataType($1.name);
                checkType($1.varType, $3.varType);                
                $1.nd = AST_mkNode(NULL, NULL, $1.name);
                $$.nd = AST_mkNode($1.nd, $3.nd, $1.name);
                codeGen_punc($4.name);                
         }
         | INPUT SENTENCE_CONSTANT IDENTIFIER SEMI_COLON {         
            checkDeclaration($3.name);
            $2.nd = AST_mkNode(NULL, NULL, $2.name);
            $3.nd = AST_mkNode(NULL, NULL, $3.name);
            $$.nd = AST_mkNode($2.nd, $3.nd, $1.name);
            $3.varType = getDataType($3.name);
            codeGen_input($2.name, $3.name, $3.varType);
        }
         | OUTPUT expression SEMI_COLON {
            $$.nd = exprRoot = AST_mkNode(NULL, $2.nd, $1.name);
            char* expr = strdup(codeGen_expression(exprRoot->right));
            codeGen_output(expr);
         }
        | conditional_statement    { 
                $$.nd = $1.nd;
          }
         | loop_statement        { 
                $$.nd = $1.nd;
          }
         
;

datatype: CHAR_TYPE { insert_type(yytext); 
}
        | INT_TYPE  { insert_type(yytext); 
        }
        | WORD_TYPE { insert_type(yytext); 
        }
        | SENTENCE_TYPE { insert_type(yytext); 
        }
        ;

definition: IDENTIFIER {
                isValidVarName($1.name);
                checkMultiDeclaration($1.name);
                storeInSymbolTable($1.name, VARIABLE, dataType, yylineno, "");
                $1.varType = dataType;
                $1.nd = AST_mkNode(NULL, NULL, $1.name);
                $$.nd = AST_mkNode($1.nd, NULL, "definition");
                codeGen_id($1.name, dataType);
            }
           | definition COMMA IDENTIFIER{
                isValidVarName($3.name);
                checkMultiDeclaration($3.name);
                storeInSymbolTable($3.name, VARIABLE, dataType, yylineno, "");
                $3.varType = dataType;
                $3.nd = AST_mkNode(NULL, NULL, $3.name);
                $$.nd = AST_mkNode($1.nd, $3.nd, "definition");
                codeGen_punc($2.name);
                codeGen_id($3.name, dataType);
           }
           | definition assignment COMMA {codeGen_punc($3.name)} definition
           | definition assignment
           ;
declaration: datatype {codeGen_dataType(dataType);} definition SEMI_COLON {                               
                $$.nd = AST_mkNode($3.nd, NULL, "declaration");
                codeGen_punc($4.name);
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
                $$.name = $1.name;
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
        storeInSymbolTable($1.name, CONSTANT, WORD, yylineno, yytext);
        $$.varType = WORD;
        $$.nd = AST_mkNode(NULL, NULL, $1.name);
        $$.name = strdup($1.name);
    }
     | SENTENCE_CONSTANT  {
         storeInSymbolTable($1.name, CONSTANT, SENTENCE, yylineno, yytext);
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
    }
    | TRUE {
            storeInSymbolTable($1.name, KEYWORD, INT, yylineno, "1");
            $$.varType = INT;
            $$.nd = NULL;
            strcpy($$.name, "1");
          }
    | FALSE {
            storeInSymbolTable($1.name, KEYWORD, INT, yylineno, "0");
            $$.varType = INT;
            $$.nd = NULL;
            strcpy($$.name, "0");
        }
     ;


conditional_statement: if_clause
    | if_clause else_clause
    ;

if_clause: IF OPEN_PAREN condition CLOSE_PAREN {codeGen_if(condExpr);} OPEN_BRACKET {codeGen_punc($6.name);} statement_list CLOSE_BRACKET {
        $$.nd = AST_mkNode($3.nd, $8.nd, $1.name);
        strcpy(condExpr, "");
        codeGen_punc($9.name);
     }
    | IF OPEN_PAREN condition CLOSE_PAREN {codeGen_if(condExpr);} statement { 
        $$.nd = AST_mkNode($3.nd, $6.nd, $1.name);
        strcpy(condExpr, "");
     }
    ;
else_clause: ELSE {codeGen_else();} statement { 
        $$.nd = AST_mkNode(NULL, $3.nd, "else");
 }
    | ELSE {codeGen_else();} OPEN_BRACKET {codeGen_punc($3.name);} statement_list CLOSE_BRACKET {
        $$.nd = AST_mkNode(NULL, $5.nd, "else");
        codeGen_punc($6.name);
     }
    ;

condition:  expression relop expression {
                checkType($1.varType, $3.varType);
                char* expr1 = strdup(codeGen_expression($1.nd));
                codeGen_clearWorkTree();
                char* expr2 = strdup(codeGen_expression($3.nd));
                strcpy(condExpr, "");
                strcpy(condExpr, strdup(codeGen_condition(expr1, $1.varType, expr2, $3.varType, $2.name)));
                $$.varType = INT;
                $$.nd = AST_mkNode($1.nd, $3.nd, $2.name);                                
            }       
          | NOT condition    {
                checkType($2.varType, INT);
                $$.varType = $2.varType;
                char* expr1 = strdup(codeGen_expression($2.nd));
                strcpy(condExpr, "");
                strcpy(condExpr, strdup(codeGen_condition(expr1, $1.varType, NULL, EMPTY, $1.name)));
                $$.nd = AST_mkNode(NULL, $2.nd, $1.name);
          }
          | expression {                
                char* expr1 = strdup(codeGen_expression($1.nd));
                strcpy(condExpr, "");
                strcpy(condExpr ,strdup(codeGen_condition(expr1, $1.varType, NULL, EMPTY, NULL)));
                $$.varType = $1.varType;
                $$.nd = $1.nd;
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

loop_statement: LOOP OPEN_PAREN condition CLOSE_PAREN {codeGen_loop(condExpr);} OPEN_BRACKET statement_list CLOSE_BRACKET {    
                    $$.nd = AST_mkNode($3.nd, $7.nd, $1.name);
                    strcpy(condExpr, "");
                    codeGen_punc($8.name);
                }
               | LOOP OPEN_PAREN condition CLOSE_PAREN  {codeGen_loop(condExpr);}  statement {                 
                    $$.nd = AST_mkNode($3.nd, $6.nd, $1.name);
                    strcpy(condExpr, "");                    
                    codeGen_punc("}");
                }
                | WHILE OPEN_PAREN condition CLOSE_PAREN {codeGen_while(condExpr);} OPEN_BRACKET statement_list CLOSE_BRACKET {
                    $$.nd = AST_mkNode($3.nd, $7.nd, $1.name);
                    strcpy(condExpr, "");
                    codeGen_punc($8.name);                    
                }                
               | WHILE OPEN_PAREN condition CLOSE_PAREN {codeGen_while(condExpr);}  statement
                { 
                    $$.nd = AST_mkNode($3.nd, $6.nd, $1.name);
                    strcpy(condExpr, "");
                    codeGen_punc("}");                     
                }
               ;

%%

void yyerror(const char* s) {
    printf("at line %d: Error; %s\n", yylineno, s);
    exit(1);
}

int main(int argc, char* argv[]) {
    static int WriteOnce = 0;
    if (argc < 3) {
        printf("Usage: %s <input_wordlang_file> <c_output_file>\n", argv[0]);
        return 1;
    }
    strcpy(outputFile, argv[2]);
    FILE* inputFile = fopen(argv[1], "r");    
    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening input file.\n");
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
    print_symbol_table();
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
