//clang 6.0.0

#include  <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int (*funptr)(int, int);

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

char* read_row()
{
    char *s = malloc(1);
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
int *get_int_values(char *strvar)
{
    int index = 0;
    static int  arr[4];
    while (*strvar) {
        printf("%c\n", *strvar);
    if (isdigit(*strvar)) {
        if(*(strvar-1) == '-')
        {
            arr[index] = -strtol(strvar, &strvar, 10);
            ++index;
        }
        else
        {
            arr[index] = strtol(strvar, &strvar, 10);
            ++index;
        }
        
    } else {
        strvar++;
    }
}
    return arr;
}

int *get_operators(char *strvar)
{
    
    //printf("%s\n", strvar);
    static int operators_arr[3];
    int index =0;
    for (int i=0; i<strlen(strvar); i++)
    {
        if      (strvar[i]=='+') {operators_arr[index]=0;++index;} // +
        else if (strvar[i]=='-') {operators_arr[index]=1;++index;} // -
    }
    return operators_arr;
}

int mix_int_op(int *numbers,int  *operators)
{
    for (int i = 0; i < 4; i++ ) {
      printf( "*(numbers + %d) : %d\n", i, *(numbers + i));
    }
    for (int i = 0; i < 3; i++ ) {
      printf( "*(operators + %d) : %d\n", i, *(operators + i));
    }
    funptr operator[] = { add, sub };
    return operator[*(operators+2)](
                operator[*(operators+1)](
                    operator[*(operators)] (*numbers, *(numbers + 1)),
                        *(numbers + 2)),
                    *(numbers + 3));
    
    
    
    
    
}


int main(void)
{   
    long result;
    int *numbers; 
    int *operators; 
    char *strvar;
    strvar = read_row();
    numbers = get_int_values(strvar);
    free(strvar);
    strvar = read_row();
    operators = get_operators(strvar);
    free(strvar);
    
    
    
    result = mix_int_op(numbers, operators);
    printf("%d\n", result);
    
    return 0;
}
