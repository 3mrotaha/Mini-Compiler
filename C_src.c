#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
typedef enum types{
    INT,
    WORD,
    SENTENCE,
    CHAR,
    EMPTY
}DataType_t;
int getSum(int a, int b);
int getSub(int a, int b);
char* getConcat(char* a, char* b);
char* strRemove(char* str1, char* str2);
char* strGetIndex(char* str, int index);
 char charRemove(char ch1, char ch2);
char* stringCharRemove(char* str1, char ch);
int getLessThan(char*, char*);
int getGreaterThan(char*, char*);
int getLessThanOrEqual(char*, char*);
int getGreaterThanOrEqual(char*, char*);
int getEqual(char*, char*);
int getNotEqual(char*, char*);
int getSum(int a, int b){
    return a + b;
}
int getSub(int a, int b){
    return a - b;
}
char* getConcat(char* a, char* b){
if(a == NULL){
    return b;
}
if(b == NULL){
    return a;
}
    char* result = calloc(100, sizeof(char));
    strcpy(result, a);
    if(strlen(a) > 1 && (strlen(b) > 1 || strchr(a, '\n') != NULL))
        strcat(result, " ");
    if(strchr(result, '\n') != NULL){
        strcat(result, b);
        while(strchr(result, '\n') != NULL){
            char* p = strchr(result, '\n');
            int indx = p - result;
            result[indx] = '\0';
            strcat(result, p + 1);
        }
        
        strcat(result, "\n");
    }
    else{
        strcat(result, b);
    }
    return result;
}
char* strRemove(char* str1, char* str2) {
    if(strchr(str1, ' ') != NULL){ // sentence expression
        // implement using strtok
        char* copy = calloc(100, sizeof(char));
        strcpy(copy, str1);
        char* result = calloc(100, sizeof(char));
        char* token = calloc(100, sizeof(char));
        token = strtok(copy, " \n");
        while(token != NULL){
            if(strcmp(token, str2) != 0){
                strcat(result, token);
                strcat(result, " ");
            }
            token = strtok(NULL, " \n");
        }
        strcat(result, "\n");
        return result;
    }
    else{ // word expression        
        if(strlen(str2) > 1){
            return strcmp(str1, str2) == 0 ? NULL : str1;
        }
        else{
            char* result = calloc(100, sizeof(char));
            strcpy(result, str1);
            char* p = strstr(result, str2);
            if(p == NULL){
                return strdup(result);
            }
            int indx = p - result;
            result[indx] = '\0';
            strcat(result, p + strlen(str2));
            return strdup(result);
        }
    }
}
char* strGetIndex(char* str, int index) {
    if (strchr(str, '\n') != NULL) {
        char* copy = calloc(100, sizeof(char));
        strcpy(copy, str);
        char* result = calloc(100, sizeof(char));
        int i = 0;
        if (index < 0) {
            // Count the number of tokens
            char* token = calloc(100, sizeof(char));
            token = strtok(copy, " \n");
            for (i = 0; token != NULL; i++) {
                token = strtok(NULL, " \n");
            }
            index = i + index;
            i = 0;
        }
        char* token = calloc(100, sizeof(char));
        strcpy(copy, str);
        token = strtok(copy, " \n");
        while (token != NULL) {
            if (i == index) {
                result = calloc(strlen(token) + 1, sizeof(char));
                strcpy(result, token);
                return result;
            }
            token = strtok(NULL, " \n");
            i++;
        }
    } else {
        char* result =calloc(2, sizeof(char));
        if(index < 0){
            index = strlen(str) + index;
        }
        result[0] = str[index];
        result[1] = '\0';
        return result;
    }
        return NULL;
    }
int getLessThan(char* str1, char* str2) {
    return strcmp(str1, str2) < 0 ? 1 : 0;
}
int getGreaterThan(char* str1, char* str2) {
    return strcmp(str1, str2) > 0 ? 1 : 0;
}
int getLessThanOrEqual(char* str1, char* str2) {
    return strcmp(str1, str2) <= 0 ? 1 : 0;
}
int getGreaterThanOrEqual(char* str1, char* str2) {
    return strcmp(str1, str2) >= 0 ? 1 : 0;
}
int getEqual(char* str1, char* str2) {
    return strcmp(str1, str2) == 0 ? 1 : 0;
}
int getNotEqual(char* str1, char* str2) {
       return strcmp(str1, str2) != 0 ? 1 : 0;
}
int main(void){
char *w1= strdup("");
char *s1= strdup("");
char *adverb= strdup("");
for(int FoorLoopInterator = 0; FoorLoopInterator < 3; FoorLoopInterator++){
	