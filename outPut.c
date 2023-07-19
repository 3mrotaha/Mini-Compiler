#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
typedef enum types
{
    INT,
    WORD,
    SENTENCE,
    CHAR,
    EMPTY
} DataType_t;
int getSum(int a, int b);
int getSub(int a, int b);
char *getConcat(char *a, char *b);
char *strRemove(char *str1, char *str2);
char *strGetIndex(char *str, int index);
int getSum(int a, int b)
{
    return a + b;
}
int getSub(int a, int b)
{
    return a - b;
}
char *getConcat(char *a, char *b)
{
    if (a == NULL)
    {
        return b;
    }
    if (b == NULL)
    {
        return a;
    }
    char *result = calloc(100, sizeof(char));
    strcpy(result, a);
    if (strlen(a) > 1 && (strlen(b) > 1 || strchr(a, '\n') != NULL))
        strcat(result, " ");
    if (strchr(result, '\n') != NULL)
    {
        strcat(result, b);
        while (strchr(result, '\n') != NULL)
        {
            char *p = strchr(result, '\n');
            int indx = p - result;
            result[indx] = '\0';
            strcat(result, p + 1);
        }

        strcat(result, "\n");
    }
    else
    {
        strcat(result, b);
    }
    return result;
}
char *strRemove(char *str1, char *str2)
{
    if (strchr(str1, ' ') != NULL)
    { // sentence expression
        // implement using strtok
        char *copy = calloc(100, sizeof(char));
        strcpy(copy, str1);
        char *result = calloc(100, sizeof(char));
        char *token = calloc(100, sizeof(char));
        token = strtok(copy, " \n");
        while (token != NULL)
        {
            if (strcmp(token, str2) != 0)
            {
                strcat(result, token);
                strcat(result, " ");
            }
            token = strtok(NULL, " \n");
        }
        strcat(result, "\n");
        return result;
    }
    else
    { // word expression
        if (strlen(str2) > 1)
        {
            return strcmp(str1, str2) == 0 ? NULL : str1;
        }
        else
        {
            char *result = calloc(100, sizeof(char));
            strcpy(result, str1);
            char *p = strstr(result, str2);
            if (p == NULL)
            {
                return strdup(result);
            }
            int indx = p - result;
            result[indx] = '\0';
            strcat(result, p + strlen(str2));
            return strdup(result);
        }
    }
}
char *strGetIndex(char *str, int index)
{
    if (strchr(str, '\n') != NULL)
    {
        char *copy = calloc(100, sizeof(char));
        strcpy(copy, str);
        char *result = calloc(100, sizeof(char));
        int i = 0;
        if (index < 0)
        {
            // Count the number of tokens
            char *token = calloc(100, sizeof(char));
            token = strtok(copy, " \n");
            for (i = 0; token != NULL; i++)
            {
                token = strtok(NULL, " \n");
            }
            index = i + index;
            i = 0;
        }
        char *token = calloc(100, sizeof(char));
        strcpy(copy, str);
        token = strtok(copy, " \n");
        while (token != NULL)
        {
            if (i == index)
            {
                result = calloc(strlen(token) + 1, sizeof(char));
                strcpy(result, token);
                return result;
            }
            token = strtok(NULL, " \n");
            i++;
        }
    }
    else
    {
        char *result = calloc(2, sizeof(char));
        if (index < 0)
        {
            index = strlen(str) + index;
        }
        result[0] = str[index];
        result[1] = '\0';
        return result;
    }
    return "\0";
}
int main(void)
{
    char *w1 = strdup("");
    char *s1 = strdup("\n"), *adverb = strdup("\n");
    for (int FoorLoopInterator = 0; FoorLoopInterator < 3; FoorLoopInterator++)
    {
        adverb = strdup(getConcat(adverb, "very"));
    }
    w1 = strdup("interesting");
    s1 = strdup(getConcat("Compilers are a\n", getConcat(adverb, w1)));
    printf("%s", getConcat(s1, "topic"));
    char *object = strdup(""), *article = strdup("");
    char notVowel = '\0';
    printf("What are you holding?\n");
    scanf("%s", object);
    notVowel = (strGetIndex(object, 0))[0];
    notVowel = (strRemove(strRemove(strRemove(strRemove(strRemove((char[2]){notVowel, '\0'}, (char[2]){'a', '\0'}), (char[2]){'e', '\0'}), (char[2]){'i', '\0'}), (char[2]){'o', '\0'}), (char[2]){'u', '\0'}))[0];
    s1 = strdup("You are holding\n");
    if (((char[2]){notVowel, '\0'})[0])
        article = strdup("a");
    else
        article = strdup("an");
    s1 = strdup(getConcat(getConcat(s1, article), object));
    printf("%s", s1);
    char *last = strdup("");
    last = strdup(strGetIndex(s1, -1));
    char *revrsd = strdup("\n");
    while (strcmp(strGetIndex(s1, 0), last) != 0)
    {
        revrsd = strdup(getConcat(revrsd, last));
        s1 = strdup(strRemove(s1, last));
        last = strdup(strGetIndex(s1, -1));
    }
    s1 = strdup(getConcat(revrsd, last));
    printf("%s", s1);
    char b = '\0', e = '\0', palindrome = '\0';
    char *savWord = strdup("");
    palindrome = ((char[2]){'Y', '\0'})[0];
    printf("Enter a word\n");
    scanf("%s", w1);
    savWord = strdup(w1);
    while ((w1)[0])
    {
        b = (strGetIndex(w1, 0))[0];
        e = (strGetIndex(w1, -1))[0];
        if (((char[2]){palindrome, '\0'})[0] == ((char[2]){'Y', '\0'})[0])
            if (((char[2]){b, '\0'})[0] != ((char[2]){e, '\0'})[0])
                palindrome = ((char[2]){'N', '\0'})[0];
        w1 = strdup(strRemove(strRemove(w1, (char[2]){b, '\0'}), (char[2]){e, '\0'}));
    }
    if (((char[2]){palindrome, '\0'})[0] == ((char[2]){'Y', '\0'})[0])
        printf("%s", getConcat(savWord, "is a palindrome\n"));
    else
        printf("%s", getConcat(savWord, "is not a palindrome\n"));
    int i = 0, j = 0, count = 0;
    count = 0;
    while ((strGetIndex(s1, count))[0])
    {
        count = getSum(count, 1);
    }
    char *s = strdup("\n");
    while (count > 1)
    {
        i = 0;
        for (int FoorLoopInterator = 0; FoorLoopInterator < getSub(count, 1); FoorLoopInterator++)
        {
            if (strcmp(strGetIndex(s1, i), strGetIndex(s1, getSum(i, 1))) > 0)
            {
                s = strdup("\n");
                j = 0;
                for (int FoorLoopInterator = 0; FoorLoopInterator < i; FoorLoopInterator++)
                {
                    s = strdup(getConcat(s, strGetIndex(s1, j)));
                    j = getSum(j, 1);
                }
                s = strdup(getConcat(s, strGetIndex(s1, getSum(i, 1))));
                s = strdup(getConcat(s, strGetIndex(s1, i)));
                j = getSum(j, 2);
                for (int FoorLoopInterator = 0; FoorLoopInterator < getSub(count, j); FoorLoopInterator++)
                {
                    s = strdup(getConcat(s, strGetIndex(s1, j)));
                    j = getSum(j, 1);
                }
                s1 = strdup(s);
            }
            i = getSum(i, 1);
        }
        count = getSub(count, 1);
    }
    printf("%s", s1);
    return 0;
}
