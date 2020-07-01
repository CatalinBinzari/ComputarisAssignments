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
    char *ptr = strvar;
    int index = 0;
    printf("%s\n", strvar);
    static int  arr[4];
    while (*ptr) {
    if (isdigit(*ptr)) {
        int val = strtol(ptr, &ptr, 10);
        arr[index] = val; ++index;
    } else {
        ptr++;
    }
}
    return arr;
}

int *get_operators(char *strvar)
{
    
    printf("%s\n", strvar);
    static int operators_arr[3];
    int index =0;
    for (int i=0; i<strlen(strvar); i++)
    {
        if(strvar[i]==43) {operators_arr[index]=0;++index;} // +
        else if (strvar[i]==45) {operators_arr[index]=1;++index;} // -
    }
    return operators_arr;
}

int mix_int_op(int *numbers,int  *operators)
{
    funptr operator[] = { add, sub };
    return operator[*(operators+2)](
                operator[*(operators+1)](
                    operator[*(operators)] (*numbers, *(numbers + 1)),
                        *(numbers + 2)),
                    *(numbers + 3));
    
    
    
    for (int i = 0; i < 4; i++ ) {
      printf( "*(numbers + %d) : %d\n", i, *(numbers + i));
    }
    for (int i = 0; i < 3; i++ ) {
      printf( "*(operators + %d) : %d\n", i, *(operators + i));
    }
}


int main(void)
{   
    int *numbers; 
    int *operators; 
    char *strvar = read_row();
    char *strop = read_row();
    numbers = get_int_values(strvar);
    free(strvar);
    operators = get_operators(strop);
    free(strop);
    
    
    
    int result = mix_int_op(numbers, operators);
    printf("%d", result);
    
    return 0;
}
