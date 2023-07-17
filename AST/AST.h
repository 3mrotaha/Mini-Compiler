#ifndef _AST_H_
#define _AST_H_

typedef struct ASTnode{
    struct ASTnode* left;
    struct ASTnode* right;
    char* token;
}ASTnode_t;

ASTnode_t *AST_mkNode(ASTnode_t* left, ASTnode_t* right, char* token);

void AST_clearTree(ASTnode_t* root);

void AST_addChild(ASTnode_t* parent, struct ASTnode* child);

void AST_getChild(ASTnode_t* parent, struct ASTnode* child);

void AST_traverse(ASTnode_t* node, int level);

#endif /* _AST_H_ */
