//clang 6.0.0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* read_string()
{
    char *s = malloc(1);
    // printf("Enter a string: \t");
    int c;
    int i = 0;
    while((c = getchar()) != '\n' && c != EOF)
    {
        s[i++] = c;
        s = realloc(s, i+1);
    }
    s[i] = '\0';
    return s;
}
int str_to_int(char* s)
{
    int i;
    sscanf(s, "%d", &i);
    return i;
}

int main(void)
{   
    int i = str_to_int(read_string());
    printf("\n%d", i);
    
    return 0;
}  
