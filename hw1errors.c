#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* foo(char* str, int* x) { 
    char* str2;
    int i;
    x = strlen(str);
    str2 = malloc(*x); 
    for (i = 0; i < *x; i++)
        str2[i] = str[*x - i]; 
    if (*x % 2 == 0) { 
        printf("%s", str);
    }
    if (*x % 2 != 0)
    {
        printf("%s", str2);
    }
    return str2;  
}

// WRONG IMPLEMENTION
//[1] line 7 - x is a pointer which recives a value without dereferencing
*x = strlen(str);
//[2] line 8 - sizeof() is missing
str2 = malloc(sizeof(*x));
//[3] line 8 - added +1, for the end char '\0'
*x = strlen(str)+1;
//[4] line 4-5 - Missing check for if *x is NULL
if(x == NULL){
    return NULL;
}
//[5] str[0] will not be copied
//[6] line 10 - str[*x] is /0 and will be copied to the first char of str2
str2[i] = str[*x - i - 1];


// CODE CONVENTIONS EXCEPTION
//[1] line 4 - x is a shortened name for pointer which is not allowed
char* foo(char* str, int* ptr) {
//[2] line 9-10 - must put {,} after a for loop
for (i = 0; i < *x; i++){
    str2[i] = str[*x - i];
}
//[3] line 8 - malloc hasn't been checked
str2 = malloc(*x);
if(str2 == NULL){
    return NULL;
}
//[4] line 4 - function name isn't a verb
char* returnOppositeWord(char* str, int* x) { 

