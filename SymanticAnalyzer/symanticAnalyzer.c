#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../SymbolTable/symbolTable.h"
#include "../SymbolTable/LinkedList/Error_States.h"
#include "../SymbolTable/LinkedList/list_config.h"
#include "../SymbolTable/LinkedList/list_privilege.h"
#include "symanticAnalyzer.h"
extern int yylineno;

List_t symbolTable;
char reservedWords[20][20] = {"char", "int", "word", "sentence", "input", "output", "loop", "if", "else", "while", "true", "false"};

/*
    1. checks if the variable is declared
*/
void checkDeclaration(char* id){
    if(lookup(id) == -1){
        printf("Error: Line %d: Variable %s isn't declared\n", yylineno, id);
        exit(1);
    }
}

/*
    1. checks if the variable is declared only once
*/
void checkMultiDeclaration(char* id){
    if(lookup(id) != -1){
        printf("Error: Line %d: Multiple declaration of variable %s\n", yylineno, id);
        exit(1);
    }
}

/*
    1. checks if the variable name is not a reserved word
*/
void isValidVarName(char* id){
    for(int i = 0; i < 20; i++){
        if(strcmp(id, reservedWords[i]) == 0){
            printf("Error: Line %d: %s is a reserved word\n", yylineno, id);
            exit(1);
        }
    }
}

/*
    1. checks if variables assigned to each other are of the same type
*/
void checkType(DataType_t type1, DataType_t type2){
    if(type2 != type1){
        printf("Line %d: Assignment of variables of different types\n", yylineno);
        exit(1);
    }
}

/*
    gets the id type from the symbol table
*/
DataType_t getDataType(char* id){
    int indx = lookup(id);
    ListEntry e;
    ListRetrieve(indx, &e, symbolTable);
    return e.dataType;
}

DataType_t checkExprDataType(DataType_t type1, DataType_t type2, char* op){
    switch(*op){
        case '+':
            if(type1 == INT && type2 == INT){
                return INT;
            }
            printf("Error: Line %d: Invalid operands to binary +\n", yylineno);
            exit(1);
        break;
        case '-':
            // permutation of types check
            if(type1 == INT && type2 == INT){
                return INT;                        
            } else if (type1 == CHAR && type2 == CHAR) {
                return CHAR;
            } else if (type1 == WORD && type2 == CHAR) {
                return WORD;
            } else if (type1 == WORD && type2 == WORD) {
                return WORD;
            } else if (type1 == SENTENCE && type2 == CHAR) {
                return SENTENCE;
            } else if (type1 == SENTENCE && type2 == WORD) {
                return SENTENCE;
            } else if (type1 == SENTENCE && type2 == SENTENCE) {
                return SENTENCE;
            }
            else {
                printf("Error: Line %d: Invalid operands to binary -\n", yylineno);
                exit(1);
            }
        break;
        case '#':
            if (type1 != INT && type2 != INT) {
                if (type1 == SENTENCE || type2 == SENTENCE) {
                    return SENTENCE;
                } else if (type1 == WORD || type2 == WORD) {
                    return WORD;
                } else {
                    return CHAR;
                }
            } else {
                printf("Error: Line %d: Invalid operands to binary #\n", yylineno);
                exit(1);
            }
        break;
        case ':':
            if (type2 == INT && type1 != INT) {
                if (type1 == SENTENCE) {
                    return WORD;
                } else if (type1 == WORD) {
                    return CHAR;
                } else if (type1 == CHAR) {
                    return CHAR;
                }
            } else {
                printf("Error: Line %d: Invalid operands to binary :\n", yylineno);
                exit(1);
            }
        break;
    }
}

// void checkConditionDataType(DataType_t type1, DataType_t type2, char* op){
//     switch()
// }