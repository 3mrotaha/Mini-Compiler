#ifndef _SYMBOL_TABLE_H_
#define _SYMBOL_TABLE_H_

#define SYMBOL_TABLE_SIZE 50000

typedef enum{
    INT,
    WORD,
    SENTENCE,
    CHAR,
    EMPTY
}DataType_t;

typedef enum{
    VARIABLE,
    KEYWORD,
    CONSTANT
}Type_t;

// symbol table definition
typedef struct symbolTable{
    char *name;
    Type_t type;
    DataType_t dataType;
    int lineNo;
    char* Value;
}symbolTable_t;

/**********************************************************************************
Name: symbolTable_init
Functionality: Initializes the symbol table
Parameters: None
Return type: void
**********************************************************************************/
void symbolTable_init(void);

/**********************************************************************************
Name: hash_symbol_index
Functionality: Calculates the hash index for the given symbol
Parameters: symbolTable_t symbol - The symbol for which the hash index needs to be calculated
Return type: int - The hash index for the given symbol
**********************************************************************************/
int hash_symbol_index(symbolTable_t symbol);

/**********************************************************************************
Name: insert_type
Functionality: Inserts the given type into the symbol table
Parameters: char *yytext - The type to be inserted
Return type: void
**********************************************************************************/
void insert_type(char *yytext);

/**********************************************************************************
Name: insert_symbol
Functionality: Inserts the given symbol into the symbol table
Parameters: symbolTable_t symbol - The symbol to be inserted
Return type: void
**********************************************************************************/
void insert_symbol(symbolTable_t symbol);

/**********************************************************************************
Name: lookup
Functionality: Searches for the given symbol in the symbol table
Parameters: char *name - The name of the symbol to be searched
Return type: int - The index of the symbol in the symbol table if found, -1 otherwise
**********************************************************************************/
int lookup(char *name);

/**********************************************************************************
Name: print_symbol_table
Functionality: Prints the entire symbol table
Parameters: None
Return type: void
**********************************************************************************/
void print_symbol_table(void);

/**********************************************************************************
Name: get_Identifier
Functionality: Searches for the given identifier in the symbol table and returns its data type and value
Parameters: char *name - The name of the identifier to be searched, char** value - Pointer to the value of the identifier
Return type: DataType_t - The data type of the identifier
**********************************************************************************/
DataType_t get_Identifier(char *name, char** value);

/**********************************************************************************
Name: update_value
Functionality: Updates the value of the given symbol in the symbol table
Parameters: char *name - The name of the symbol whose value needs to be updated, char* value - The new value of the symbol
Return type: void
**********************************************************************************/
void update_value(char *name, char* value);

/**********************************************************************************
Name: search_for_duplicates
Functionality: Searches for duplicate symbols in the symbol table
Parameters: char* name - The name of the symbol to be searched
Return type: int - 1 if duplicate symbol found, 0 otherwise
**********************************************************************************/
int search_for_duplicates(char* name);

#endif // _SYMBOL_TABLE_H_