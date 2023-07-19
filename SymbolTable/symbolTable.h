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


void symbolTable_init(void);
int hash_symbol_index(symbolTable_t symbol);
void insert_type(char *yytext);
void insert_symbol(symbolTable_t symbol);
int lookup(char *name);
void print_symbol_table(void);
DataType_t get_Identifier(char *name, char** value);
void update_value(char *name, char* value);
int search_for_duplicates(char* name);

#endif // _SYMBOL_TABLE_H_