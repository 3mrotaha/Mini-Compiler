#ifndef _SYMANTIC_ANALYZER_
#define _SYMANTIC_ANALYZER_
#include "..\SymbolTable\symbolTable.h"

/*
    1. checks if the variable is declared
*/
void checkDeclaration(char* id);

/*
    1. checks if the variable is declared only once
*/
void checkMultiDeclaration(char* id);

/*
    1. checks if the variable name is not a reserved word
*/
void isValidVarName(char* id);

/*
    1. checks if variables assigned to each other are of the same type
*/
void checkType(DataType_t type1, DataType_t type2);
/*
    gets the id type from the symbol table
*/
DataType_t getDataType(char* id);

DataType_t checkExprDataType(DataType_t type1, DataType_t type2, char* op);
#endif