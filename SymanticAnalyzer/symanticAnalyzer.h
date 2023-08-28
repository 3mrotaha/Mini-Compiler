#ifndef _SYMANTIC_ANALYZER_
#define _SYMANTIC_ANALYZER_
#include "..\SymbolTable\symbolTable.h"

/**********************************************************************************
Name: checkDeclaration
Functionality: Checks if the variable is declared
Parameters: char* id - the identifier of the variable to check
Return type: void
**********************************************************************************/
void checkDeclaration(char* id);

/**********************************************************************************
Name: checkMultiDeclaration
Functionality: Checks if the variable is declared only once
Parameters: char* id - the identifier of the variable to check
Return type: void
**********************************************************************************/
void checkMultiDeclaration(char* id);

/**********************************************************************************
Name: isValidVarName
Functionality: Checks if the variable name is not a reserved word
Parameters: char* id - the identifier of the variable to check
Return type: void
**********************************************************************************/
void isValidVarName(char* id);

/**********************************************************************************
Name: checkType
Functionality: Checks if variables assigned to each other are of the same type
Parameters: DataType_t type1 - the data type of the first variable
            DataType_t type2 - the data type of the second variable
Return type: void
**********************************************************************************/
void checkType(DataType_t type1, DataType_t type2);

/**********************************************************************************
Name: getDataType
Functionality: Gets the id type from the symbol table
Parameters: char* id - the identifier of the variable to get the data type for
Return type: DataType_t - the data type of the variable
**********************************************************************************/
DataType_t getDataType(char* id);

/**********************************************************************************
Name: checkExprDataType
Functionality: Checks the data type of an expression
Parameters: DataType_t type1 - the data type of the first operand
            DataType_t type2 - the data type of the second operand
            char* op - the operator used in the expression
Return type: DataType_t - the data type of the expression
**********************************************************************************/
DataType_t checkExprDataType(DataType_t type1, DataType_t type2, char* op);

#endif