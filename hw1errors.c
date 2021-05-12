#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* foo(char* str, int* x) { // x is a shortened name that is not allowed (2) + function name isnt a verb (2)
    char* str2;
    int i;
    x = strlen(str); // x is a pointer which recives a value without dereferencing (we fill its place not his value) (1)
    str2 = malloc(*x); // sizeof() is missing (1) + malloc return value isn't checked (1/2) +  malloc reads junk value
    for (i = 0; i < *x; i++)
        str2[i] = str[*x - i]; // str[0] will never be copied (1) + must put {,} after a for loop (2)
    if (*x % 2 == 0) { 
        printf("%s", str);
    }
    if (*x % 2 != 0)
    {
        printf("%s", str2);
    }
    return str2;  
}

