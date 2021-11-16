#include<stdio.h>


void showbit(int n)
{    
 if(n>1){
        showbit(n/2);
        printf(" ");
    }
    printf("%d",n%2);
}
void showoct(int n)
{    
 if(n>7){
        showoct(n/8);
    }
    printf("%d",n%8);
}
void showhex(int n)
{
    if(n>15){
        showhex(n/16);
    }
    printf("%d",n%16);
}
int main()
{
    while (1)
    {
        int a;
        printf("please input DEC num: ");
        scanf("%d",&a);
        printf("DEC %d to BIN is: ",a);
        showbit(a);
        printf("\n");
        printf("DEC %d to OCT is: ",a);
        showoct(a);
        printf("\n");
        printf("DEC %d to HEX is: ",a);
        showhex(a);
        printf("\n");
    }
    
    return 0;
}
