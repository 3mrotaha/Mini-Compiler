#ifndef CODEGENERATOR_H
#define CODEGENERATOR_H

#include <stdio.h>
#include "../AST/AST.h"
#include "../SymbolTable/SymbolTable.h"

/**********************************************************************************
Name: addExprNode
Functionality: Adds a new expression node to the abstract syntax tree (AST)
Parameters: 
    - value: the value of the expression node
    - left: pointer to the left child of the expression node
    - right: pointer to the right child of the expression node
Return type: void
**********************************************************************************/
void addExprNode(char* value, ASTnode_t* left, ASTnode_t* right);

/**********************************************************************************
Name: clearTree
Functionality: Clears the abstract syntax tree (AST)
Parameters: 
    - root: pointer to the root node of the AST
Return type: void
**********************************************************************************/
void clearTree(ASTnode_t* root);

/**********************************************************************************
Name: codeGen_id
Functionality: Generates code for an identifier
Parameters: 
    - id: the identifier to generate code for
    - type: the data type of the identifier
Return type: void
**********************************************************************************/
void codeGen_id(char* id, DataType_t type);

/**********************************************************************************
Name: codeGen_idAssign
Functionality: Generates code for assigning a value to an identifier
Parameters: 
    - id: the identifier to assign a value to
Return type: void
**********************************************************************************/
void codeGen_idAssign(char* id);

/**********************************************************************************
Name: codeGen_dataType
Functionality: Generates code for a data type
Parameters: 
    - type: the data type to generate code for
Return type: void
**********************************************************************************/
void codeGen_dataType(DataType_t type);

/**********************************************************************************
Name: codeGen_Init
Functionality: Initializes the code generator
Parameters: none
Return type: void
**********************************************************************************/
void codeGen_Init(void);

/**********************************************************************************
Name: codeGen_Close
Functionality: Closes the code generator
Parameters: none
Return type: void
**********************************************************************************/
void codeGen_Close(void);

/**********************************************************************************
Name: codeGen_initVar
Functionality: Generates code for initializing a variable
Parameters: 
    - type: the data type of the variable to initialize
Return type: void
**********************************************************************************/
void codeGen_initVar(DataType_t type);

/**********************************************************************************
Name: codeGen_input
Functionality: Generates code for inputting a value from the user
Parameters: 
    - prompt_val: the prompt to display to the user
    - id: the identifier to store the input value in
    - type: the data type of the input value
Return type: void
**********************************************************************************/
void codeGen_input(char* prompt_val, char* id, DataType_t type);

/**********************************************************************************
Name: codeGen_output
Functionality: Generates code for outputting a value
Parameters: 
    - expression: the expression to output
Return type: void
**********************************************************************************/
void codeGen_output(char* expression);

/**********************************************************************************
Name: codeGen_assign
Functionality: Generates code for assigning a value to an expression
Parameters: 
    - expression: the expression to assign a value to
    - type: the data type of the expression
Return type: void
**********************************************************************************/
void codeGen_assign(char* expression, DataType_t type);

/**********************************************************************************
Name: codeGen_declare
Functionality: Generates code for declaring a variable
Parameters: 
    - id: the identifier of the variable to declare
    - type: the data type of the variable to declare
Return type: void
**********************************************************************************/
void codeGen_declare(char* id, DataType_t type);

/**********************************************************************************
Name: codeGen_expression
Functionality: Generates code for an expression
Parameters: 
    - root: pointer to the root node of the expression
Return type: char*
**********************************************************************************/
char* codeGen_expression(ASTnode_t *root);

/**********************************************************************************
Name: codeGen_condition
Functionality: Generates code for a condition
Parameters: 
    - expr1: the first expression to compare
    - dt1: the data type of the first expression
    - expr2: the second expression to compare
    - dt2: the data type of the second expression
    - op: the comparison operator
Return type: char*
**********************************************************************************/
char* codeGen_condition(char *expr1, DataType_t dt1, char *expr2, DataType_t dt2, char* op);

/**********************************************************************************
Name: codeGen_clearWorkTree
Functionality: Clears the work tree used during code generation
Parameters: none
Return type: void
**********************************************************************************/
void codeGen_clearWorkTree(void);

/**********************************************************************************
Name: codeGen_if
Functionality: Generates code for an if statement
Parameters: 
    - condition: the condition to check
Return type: void
**********************************************************************************/
void codeGen_if(char* condition);

/**********************************************************************************
Name: codeGen_else
Functionality: Generates code for an else statement
Parameters: none
Return type: void
**********************************************************************************/
void codeGen_else(void);

/**********************************************************************************
Name: codeGen_while
Functionality: Generates code for a while loop
Parameters: 
    - condition: the condition to check
Return type: void
**********************************************************************************/
void codeGen_while(char* condition);

/**********************************************************************************
Name: codeGen_loop
Functionality: Generates code for a loop
Parameters: 
    - id: the identifier of the loop variable
Return type: void
**********************************************************************************/
void codeGen_loop(char* id);

/**********************************************************************************
Name: codeGen_helpersPrototypes
Functionality: Generates prototypes for helper functions
Parameters: none
Return type: void
**********************************************************************************/
void codeGen_helpersPrototypes(void);

/**********************************************************************************
Name: codeGen_helpersImplementations
Functionality: Generates implementations for helper functions
Parameters: none
Return type: void
**********************************************************************************/
void codeGen_helpersImplementations(void);

/**********************************************************************************
Name: codeGen_punc
Functionality: Generates code for a punctuation mark
Parameters: 
    - punc: the punctuation mark to generate code for
Return type: void
**********************************************************************************/
void codeGen_punc(char* punc);

/**********************************************************************************
Name: writeExpressionTreeToFile
Functionality: Writes the abstract syntax tree (AST) to a file
Parameters: 
    - root: pointer to the root node of the AST
    - file: pointer to the file to write the AST to
    - level: the level of the current node in the AST
Return type: void
**********************************************************************************/
void writeExpressionTreeToFile(ASTnode_t* root, FILE* file, int level);

#endif /* CODEGENERATOR_H */
