//clang 6.0.0

#include  <stdio.h>
void generate_hystogram(int *word_counter, int *word_len)
{
    printf("[%d] ", *word_counter);
    for(int i = 0; i< *word_len; ++i)
    {
        printf("*");
    }
    printf("\n");
}
int main(void)
{
    int c, word_len = 0, word_counter = 0;
    while(c = getchar())
    {
        //printf("%d\n", c);
        if (c == ' ' && word_len > 0) { generate_hystogram(&word_counter, &word_len); word_len = 0; ++word_counter; }
        else if (c == -1 ) { generate_hystogram(&word_counter, &word_len); break; }
        else if (c == ' ' || c == 13 || c == 10) continue; //ascii[13] == \n, ascii[10] = Carriage Return?
        else ++word_len;
    }
    
    return 0;
}
