#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AST.h"
#include "../SymbolTable/symbolTable.h"


// Global variables
ASTnode_t* root = NULL;
FILE* traverseFile = NULL;
// Function definitions
ASTnode_t *AST_mkNode(ASTnode_t* left, ASTnode_t* right, char* token){
    ASTnode_t* node = (ASTnode_t*)malloc(sizeof(ASTnode_t));
    node->left = left;
    node->right = right;
    node->token = strdup(token);
    return node;
}

void AST_clearTree(ASTnode_t* root){
    if(root->left != NULL){
        AST_clearTree(root->left);
    }
    if(root->right != NULL){
        AST_clearTree(root->right);
    }
    free(root->token);
    free(root);
    root = NULL;
}

void AST_addChild(ASTnode_t* parent, struct ASTnode* child){
    if(parent->left == NULL){
        parent->left = child;
    }else{
        parent->right = child;
    }
}

void AST_getChild(ASTnode_t* parent, struct ASTnode* child){
    if(parent->left != NULL){
        child = parent->left;
    }else{
        child = parent->right;
    }
}

void AST_traverse(ASTnode_t* node, int level) {
    if (node->left != NULL) {
        AST_traverse(node->left, level + 1);
    }

    for (int i = 0; i < level; i++) {
        fprintf(traverseFile, "\t");
    }

    fprintf(traverseFile, "|---(%d) %s\n",level, node->token); // execute node code

    if (node->right != NULL) {
        AST_traverse(node->right, level + 1);
    }
}


