#ifndef _AST_H_
#define _AST_H_

/**********************************************************************************
Name: ASTnode
Functionality: This struct represents a node in an abstract syntax tree (AST).
Parameters: None
Return type: ASTnode_t
**********************************************************************************/
typedef struct ASTnode{
    struct ASTnode* left;   // Pointer to the left child node.
    struct ASTnode* right;  // Pointer to the right child node.
    char* token;            // The token associated with this node.
}ASTnode_t;

/**********************************************************************************
Name: AST_mkNode
Functionality: Creates a new AST node with the given left and right child nodes and token.
Parameters: 
    - left: Pointer to the left child node.
    - right: Pointer to the right child node.
    - token: The token associated with this node.
Return type: ASTnode_t*
**********************************************************************************/
ASTnode_t *AST_mkNode(ASTnode_t* left, ASTnode_t* right, char* token);

/**********************************************************************************
Name: AST_clearTree
Functionality: Recursively frees all memory associated with the given AST.
Parameters: 
    - root: Pointer to the root node of the AST to be cleared.
Return type: void
**********************************************************************************/
void AST_clearTree(ASTnode_t* root);

/**********************************************************************************
Name: AST_addChild
Functionality: Adds the given child node to the given parent node.
Parameters: 
    - parent: Pointer to the parent node.
    - child: Pointer to the child node to be added.
Return type: void
**********************************************************************************/
void AST_addChild(ASTnode_t* parent, struct ASTnode* child);

/**********************************************************************************
Name: AST_getChild
Functionality: Gets the child node at the given index for the given parent node.
Parameters: 
    - parent: Pointer to the parent node.
    - child: Pointer to the child node to be retrieved.
Return type: void
**********************************************************************************/
void AST_getChild(ASTnode_t* parent, struct ASTnode* child);

/**********************************************************************************
Name: AST_traverse
Functionality: Traverses the given AST in a depth-first manner, printing out each node's token and level.
Parameters: 
    - node: Pointer to the root node of the AST to be traversed.
    - level: The level of the current node in the AST.
Return type: void
**********************************************************************************/
void AST_traverse(ASTnode_t* node, int level);

#endif /* _AST_H_ */