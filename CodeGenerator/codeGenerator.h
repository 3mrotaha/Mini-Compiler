#ifndef CODEGENERATOR_H
#define CODEGENERATOR_H

#include <stdio.h>
#include "../AST/AST.h"
#include "../SymbolTable/SymbolTable.h"

// add node to the tree
void addExprNode(char* value, ASTnode_t* left, ASTnode_t* right);

// clear the tree
void clearTree(ASTnode_t* root);

void codeGen_id(char* id, DataType_t type);

void codeGen_idAssign(char* id);

void codeGen_dataType(DataType_t type);

void codeGen_Init(void);

void codeGen_Close(void);

void codeGen_initVar(DataType_t type);

void codeGen_input(char* prompt_val, char* id, DataType_t type);

void codeGen_output(char* expression);

void codeGen_assign(char* expression, DataType_t type);

void codeGen_declare(char* id, DataType_t type);

char* codeGen_expression(ASTnode_t *root);

char* codeGen_condition(char *expr1, DataType_t dt1, char *expr2, DataType_t dt2, char* op);

void codeGen_clearWorkTree(void);

void codeGen_if(char* condition);

void codeGen_else(void);

void codeGen_while(char* condition);

void codeGen_loop(char* id);

void codeGen_helpersPrototypes(void);

void codeGen_helpersImplementations(void);

void codeGen_punc(char* punc);

void writeExpressionTreeToFile(ASTnode_t* root, FILE* file, int level);

#endif /* CODEGENERATOR_H */
