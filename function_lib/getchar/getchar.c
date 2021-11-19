#include<string.h>
#include<stdio.h> 


int main(void)
{
    char ch ;
    int num ;
    
    num = 0 ;
    
    printf("please input string: \n")  ;
    
    while((ch = getchar()) != '\n')
    {
            printf("%c", ch)    ;
            num++   ;
    }
    
    printf("\nthe string legth is %d \n", num) ;
    return 0    ;
}
 