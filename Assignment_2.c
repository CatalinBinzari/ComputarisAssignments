//clang 6.0.0

#include  <stdio.h>
#define FINISH 100
#define BEGIN 1
void display_ping()
{
    printf("Ping");
}
void display_pong()
{
    printf("Pong");
}
void display_pingpong()
{
    display_ping();
    display_pong();
}
int main(void)
{   
    for(int index = BEGIN; index <= FINISH; ++index)
    {
        if(index % 2 == 0 && index % 3 == 0) display_pingpong();
        else if(index % 2 == 0) display_ping();
        else if(index % 3 == 0) display_pong();
        else printf("%d", index);
  
        printf("\n");
        
    }
    
    return 0;
}
