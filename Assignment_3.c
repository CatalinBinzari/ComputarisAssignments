//clang 6.0.0

#include  <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

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
void display_arr(int letters[26][2], int *letter_index)
{
    for(int i = 0; i < *letter_index; ++i)
    {
        printf("\n%c : %d", letters[i][0], letters[i][1]);
    }
}
bool verify_repating(char *strvar, int letters[26][2], int i)
{
    for(int r = 0; r < 26; ++r)
        if(strvar[i] == letters[r][0]) return true;
    return false;
}

void count_letters(char *strvar, int letters[26][2], int i, int *letter_index, int *counter)
{
    letters[*letter_index][0] = strvar[i];
                
    for(int j = 0; j < strlen(strvar); ++j)
        if(strvar[j] == letters[*letter_index][0]) ++*counter; 
                    
    letters[*letter_index][1] = *counter;
    ++*letter_index;
    *counter = 0;
}

int main(void)
{   int letters[26][2] = {};
    int letter_index = 0, counter = 0;
    bool repeated;
    
    char *strvar = read_row();
 
    for(int i = 0; i < strlen(strvar); ++i)
    {
        
        if(strvar[i]>='a' && strvar[i]<='z' || strvar[i]>='A' && strvar[i]<='Z') 
        {  
            repeated = verify_repating(strvar, letters, i);
            if(!repeated){
                count_letters(strvar, letters, i, &letter_index, &counter);
            }
        }
    }
    
    display_arr(letters, &letter_index);
 
    return 0;
}
