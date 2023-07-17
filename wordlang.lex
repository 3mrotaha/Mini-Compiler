%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AST\AST.h"
#include "SymbolTable\symbolTable.h"
#include "wordlang.tab.h"
%}

%option yylineno


%%

[ \t\n]         /* Ignore whitespace */
"//"(.)*        /* Ignore comments */

"char"          { yylval.nodeType.name = strdup(yytext); yylval.nodeType.varType=(DataType_t)CHAR; yylval.nodeType.type = KEYWORD; return CHAR_TYPE; }
"int"           { yylval.nodeType.name = strdup(yytext); yylval.nodeType.varType=(DataType_t)INT; yylval.nodeType.type = KEYWORD; return INT_TYPE; }
"word"          { yylval.nodeType.name = strdup(yytext); yylval.nodeType.varType=(DataType_t)WORD; yylval.nodeType.type = KEYWORD; return WORD_TYPE; }
"sentence"      { yylval.nodeType.name = strdup(yytext); yylval.nodeType.varType=(DataType_t)SENTENCE; yylval.nodeType.type = KEYWORD; return SENTENCE_TYPE; }

"input"         { yylval.nodeType.name = strdup(yytext); yylval.nodeType.varType=(DataType_t)EMPTY; yylval.nodeType.type = KEYWORD;return INPUT; }
"output"        { yylval.nodeType.name = strdup(yytext); yylval.nodeType.varType=(DataType_t)EMPTY; yylval.nodeType.type = KEYWORD;return OUTPUT; }
"if"            { yylval.nodeType.name = strdup(yytext); yylval.nodeType.varType=(DataType_t)EMPTY; yylval.nodeType.type = KEYWORD;return IF; }
"else"          { yylval.nodeType.name = strdup(yytext); yylval.nodeType.varType=(DataType_t)EMPTY; yylval.nodeType.type = KEYWORD;return ELSE; }
"while"         { yylval.nodeType.name = strdup(yytext); yylval.nodeType.varType=(DataType_t)EMPTY; yylval.nodeType.type = KEYWORD;return WHILE; }
"loop"          { yylval.nodeType.name = strdup(yytext); yylval.nodeType.varType=(DataType_t)EMPTY; yylval.nodeType.type = KEYWORD;return LOOP; }

"true"          { yylval.nodeType.name = strdup(yytext); yylval.nodeType.intVal = 1; yylval.nodeType.varType=(DataType_t)INT; yylval.nodeType.type = KEYWORD; return TRUE; }
"false"         { yylval.nodeType.name = strdup(yytext); yylval.nodeType.intVal = 0; yylval.nodeType.varType=(DataType_t)INT; yylval.nodeType.type = KEYWORD; return FALSE; }
""              { yylval.nodeType.name = strdup(yytext); yylval.nodeType.intVal = 0; yylval.nodeType.varType=(DataType_t)INT; yylval.nodeType.type = KEYWORD; return FALSE; }

"'"(.){1}"'"    { yylval.nodeType.name = strdup(yytext); yylval.nodeType.charVal = yytext[1]; yylval.nodeType.varType=(DataType_t)CHAR; yylval.nodeType.type = CONSTANT;return CHAR_CONSTANT; }
"\""([^"\t\n ]*?)"\""   { yylval.nodeType.name = strdup(yytext); yylval.nodeType.wordVal = strdup(yytext + 1); yylval.nodeType.type = CONSTANT;yylval.nodeType.wordVal[strlen(yylval.nodeType.wordVal) - 1] = '\0'; yylval.nodeType.varType=(DataType_t)WORD; return WORD_CONSTANT; }
"^"(.)[^^]*"^"    { yylval.nodeType.name = (char*) malloc(sizeof(yytext)); strcpy(yylval.nodeType.name, yytext); yylval.nodeType.name[0] = '\"'; yylval.nodeType.name[strlen(yylval.nodeType.name) - 1] = '\0'; strcat(yylval.nodeType.name, "\\n\""); yylval.nodeType.name[strlen(yylval.nodeType.name) + 1] = '\0'; yylval.nodeType.wordVal = strdup(yytext + 1); yylval.nodeType.type = CONSTANT; yylval.nodeType.wordVal[strlen(yylval.nodeType.wordVal) - 1] = '\n'; yylval.nodeType.varType=(DataType_t)SENTENCE; return SENTENCE_CONSTANT; }
"-"[0-9]+        { yylval.nodeType.name = strdup(yytext); yylval.nodeType.intVal = atoi(yytext + 1) * -1; yylval.nodeType.type = CONSTANT; yylval.nodeType.varType=(DataType_t)INT; return INT_CONSTANT; }
[0-9]+           { yylval.nodeType.name = strdup(yytext); yylval.nodeType.intVal = atoi(yytext); yylval.nodeType.type = CONSTANT; yylval.nodeType.varType=(DataType_t)INT; return INT_CONSTANT; }
[a-zA-Z_][a-zA-Z0-9_]{0,31} {yylval.nodeType.name = strdup(yytext); yylval.nodeType.type = VARIABLE; return IDENTIFIER; }

"+"             { yylval.nodeType.name = strdup(yytext); yylval.nodeType.type = (Type_t)KEYWORD; return ADD; }
"-"             { yylval.nodeType.name = strdup(yytext); yylval.nodeType.type = (Type_t)KEYWORD; return REMOVE; }
"#"             { yylval.nodeType.name = strdup(yytext); yylval.nodeType.type = (Type_t)KEYWORD; return CONCAT; }
":"             { yylval.nodeType.name = strdup(yytext); yylval.nodeType.type = (Type_t)KEYWORD; return GET; }
"("             { yylval.nodeType.name = strdup(yytext); yylval.nodeType.type = (Type_t)KEYWORD; return OPEN_PAREN; }
")"             { yylval.nodeType.name = strdup(yytext); yylval.nodeType.type = (Type_t)KEYWORD; return CLOSE_PAREN; }
"<="            { yylval.nodeType.name = strdup(yytext); yylval.nodeType.type = (Type_t)KEYWORD; return LE; }
">="            { yylval.nodeType.name = strdup(yytext); yylval.nodeType.type = (Type_t)KEYWORD; return GE; }
"<"             { yylval.nodeType.name = strdup(yytext); yylval.nodeType.type = (Type_t)KEYWORD; return LT; }
">"             { yylval.nodeType.name = strdup(yytext); yylval.nodeType.type = (Type_t)KEYWORD; return GT; }
"=="            { yylval.nodeType.name = strdup(yytext); yylval.nodeType.type = (Type_t)KEYWORD; return EQ; }
"!="            { yylval.nodeType.name = strdup(yytext); yylval.nodeType.type = (Type_t)KEYWORD; return NE; }
"!"             { yylval.nodeType.name = strdup(yytext); yylval.nodeType.type = (Type_t)KEYWORD; return NOT; }
"="             { yylval.nodeType.name = strdup(yytext); yylval.nodeType.type = (Type_t)KEYWORD; return EQUAL; }
";"             { yylval.nodeType.name = strdup(yytext); yylval.nodeType.type = (Type_t)KEYWORD; return SEMI_COLON; }
"{"             { yylval.nodeType.name = strdup(yytext); yylval.nodeType.type = (Type_t)KEYWORD; return OPEN_BRACKET; }
"}"             { yylval.nodeType.name = strdup(yytext); yylval.nodeType.type = (Type_t)KEYWORD; return CLOSE_BRACKET; }
","             { yylval.nodeType.name = strdup(yytext); yylval.nodeType.type = (Type_t)KEYWORD; return COMMA; }


.               { printf("Invalid syntax: %s\n", yytext); exit(1); }

%%

int yywrap(void) {
    return 1;
}

