//clang 6.0.0
#include <stdio.h>
#include <string.h>
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
void print(char *str, int index) 
{ 
    if (index == strlen(str)) 
    {   
        //printf("ind: %d\n", index);
        printf("%s\n", str);
        return ; 
    } 
  
    if (str[index] == '?') 
    {
        //printf("index for 0:%d\n",index);
        str[index] = '0'; 
        //printf("doilea: %s\n",str);
        print(str, index + 1); 
        
        
        
        //printf("index for 1:%d\n",index);
        str[index] = '1'; 
        //printf("treilea: %s\n",str);
        print(str, index + 1); 
        str[index] = '?'; 
    } 
    else
     {
        //printf("test: %s | %d\n",str, index);
        //printf("patrulea %s\n",str);
        print(str, index + 1); 
    }
   
} 
int main(void) 
{ 
    char *str = read_row(); 
    //char * str = malloc(8);
    //str = "1??01\0";
    print(str, 0);
  
    return 0; 
} 
