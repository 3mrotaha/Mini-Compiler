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
int getSum(int a, int b){
return a + b;
}
int getSub(int a, int b){
return a - b;
}
char* getConcat(char* a, char* b){
char* result = malloc(sizeof(char) * 100);
strcpy(result, a);
strcat(result, " ");
strcat(result, b);
if(strchr(result, '\n') != NULL){
char* p = strchr(result, '\n');
int indx = p - result;
memmove(result + indx, result + indx + 1, strlen(result) - indx);
}
return result;
}
 char charRemove(char ch1, char ch2) {
 if (ch1 == ch2) {
    return '\0'; // Return null character to indicate removal
} else {
    return ch1;
}
}
char* strRemove(char* str1, char* str2) {
    char* result = malloc(sizeof(char) * 100);
    char* p = strstr(str1, str2);
    if (p != NULL) {
        size_t len2 = strlen(str2);
        size_t index = p - str1;
        strncpy(result, str1, index);
        result[index] = '\0';
        strcat(result, p + len2);
    } else {
        strcpy(result, str1);
    }
    return result;
}
char* stringCharRemove(char* str1, char ch) {
char* result = malloc(sizeof(char) * 100);
char str2[2];
str2[0] = ch;
str2[1] = '\0';
char* p = strchr(str1, ch);
if (p != NULL) {
    size_t index = p - str1;
    strncpy(result, str1, index);
    result[index] = '\0';
    strcat(result, p + 1);
} else {
strcpy(result, str1);
}
return result;
}
char* strGetIndex(char* str, int index) {
    if (strchr(str, '\n') != NULL) {
        char* copy = malloc(sizeof(char) * 100);
        strcpy(copy, str);
        char* result = malloc(sizeof(char) * 100);
        int i = 0;
        if (index < 0) {
            // Count the number of tokens
            char* token = malloc(sizeof(char) * 100);
            token = strtok(copy, " \n");
            for (i = 0; token != NULL; i++) {
                token = strtok(NULL, " \n");
            }
            i = i - index;
        }
        char* token = malloc(sizeof(char) * 100);
        token = strtok(copy, " \n");
        while (token != NULL) {
            if (i == index) {
                result = malloc(sizeof(char) * strlen(token) + 1);
                strcpy(result, token);
                return result;
            }
            token = strtok(NULL, " \n");
            i++;
        }
    } else {
        char* result = malloc(sizeof(char) * 2);
        if(index < 0){
            index = strlen(str) + index;
        }
        result[0] = str[index];
        result[1] = '\0';
        return result;
    }
    return "\0";
}
int main(void){
char d= '\0';
d= (strGetIndex("project",-2))[0];
printf("%s", (char[2]){d, '\0'});
return 0;
}
