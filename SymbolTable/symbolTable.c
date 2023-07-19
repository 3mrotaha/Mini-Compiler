#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList/Error_States.h"
#include "LinkedList/list_config.h"
#include "LinkedList/list_privilege.h"
#include "symbolTable.h"
int symbolTableIndex = 0;
DataType_t dataType;
List_t symbolTable;
extern int yylineno;
void symbolTable_init(void){
    CreateList(&symbolTable);
}

int hash_symbol_index(symbolTable_t symbol) {
    unsigned long long hash = 5381; // Initial hash value
    int c, i = 0;

    while ((c = *(symbol.name + i))) {
        hash = ((hash << 5) + hash) + c; // Update hash value
        i++;
    }

    return hash % SYMBOL_TABLE_SIZE; // Map hash value to the range [0, n]
}

void insert_type(char* yytext){
    if(strcmp(yytext, "int") == 0){
        dataType = INT;
    }
    else if(strcmp(yytext, "sentence") == 0){
        dataType = SENTENCE;
    }
    else if(strcmp(yytext, "char") == 0){
        dataType = CHAR;
    }
    else if(strcmp(yytext, "word") == 0){
        dataType = WORD;
    }
}

void insert_symbol(symbolTable_t symbol){
    if(symbolTableIndex < SYMBOL_TABLE_SIZE){
        int i = search_for_duplicates(symbol.name);
        char* p = malloc(sizeof(char) * 10);
        int indx = hash_symbol_index(symbol);
        itoa(indx, p, 10);
        symbol.name = strdup(p);
        if(i == -1){            
            ListInsert(symbolTableIndex++, symbol, &symbolTable);
        }
        //printf("line %d: Variable %s successfully declared\n", symbol.lineNo, symbol.name);
    }
    else{
        printf("No more space to store variable %s\n", symbol.name);
        exit(1);
    }
}

int lookup(char *name){
    char* p = malloc(sizeof(char) * 10);
    int indx = hash_symbol_index((symbolTable_t) {.name = strdup(name)});
    itoa(indx, p, 10);
    int i;
    ListEntry e;
    for(i = 0; i < symbolTableIndex; i++){
        ListRetrieve(i, &e, symbolTable);
        if(strcmp(e.name, p) == 0){
            //printf("var %s type %d\n", name, symbolTable[i].dataType);
            return i;
        }
    }
    return -1;
}

void print_symbol_table(void){
    int i;
    FILE* fp = fopen("symbol_table.txt", "w+");
    fprintf(fp,"LINE\t\t\tTYPE\t\t\tDATA TYPE\t\t\tID\t\t\tVALUE\n");
    fprintf(fp,"----------------------------------------------------------------------------------------------------------------\n");
    ListEntry e;
    for(int i = 0; i < symbolTableIndex; i++){
        ListRetrieve(i, &e, symbolTable);
        if(e.name != NULL){
            fprintf(fp,"%d\t\t\t", e.lineNo);
            switch(e.type){
                case KEYWORD:
                    fprintf(fp,"KEYWORD \t\t\t");
                    break;
                case VARIABLE:
                    fprintf(fp,"VARIABLE\t\t\t");
                    break;
                case CONSTANT:
                    fprintf(fp,"CONSTANT\t\t\t");
                    break;
                default:
                    fprintf(fp,"N/A\t\t\t");
            }

            switch(e.dataType){
                case INT:
                    fprintf(fp,"INT     \t\t\t");
                    break;
                case SENTENCE:
                    fprintf(fp,"SENTENCE\t\t\t");
                    break;
                case CHAR:
                    fprintf(fp,"CHAR    \t\t\t");
                    break;
                case WORD:
                    fprintf(fp,"WORD    \t\t\t");
                    break;
                default:
                    fprintf(fp,"N/A     \t\t\t");
            }

            fprintf(fp,"%s\t\t\t", e.name);

            switch(e.dataType){
                case INT:
                    fprintf(fp,"%s\n", e.Value);
                    break;
                case SENTENCE:
                    fprintf(fp,"%s\n", e.Value);
                    break;
                case CHAR:
                    fprintf(fp,"%s\n", e.Value);
                    break;
                case WORD:
                    fprintf(fp,"%s\n", e.Value);
                    break;
                default:
                    fprintf(fp,"N/A\t\t\t\n");
            }
        }
    }
}

void update_value(char *name, char* value){
    int index = lookup(name);
    ListEntry e;    
    if(index == -1){
        printf("line %d: Variable %s not declared can't update\n", yylineno, name);
        exit(1);
    }
    ListRetrieve(index, &e, symbolTable);
    e.Value = strdup(value);
}

int search_for_duplicates(char* name){    
    return lookup(name);
}

DataType_t get_Identifier(char *name, char** value){
    int index = lookup(name);

    if(index == -1){
        printf("line %d: Variable %s not declared\n", yylineno, name);
        exit(1);
    }

    ListEntry e;
    ListRetrieve(index, &e, symbolTable);
    *value = strdup(e.Value);
    return e.dataType;
}