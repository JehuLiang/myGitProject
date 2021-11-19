#include <stdio.h>

int strcmp (const unsigned char *src, const unsigned char *dst)
{
        int ret = 0 ;
        while(!(ret = *(unsigned char *)src - *(unsigned char *)dst) && *dst)
        {
                ++src;
                ++dst;
        }
        if ( ret < 0 )
                ret = -1 ;
        else if ( ret > 0 )
                ret = 1 ;
        return( ret );
}

int main(void)
{
    char* str_1 = "a" ;
    char * str_2 = "a" ;
    char* str_3 = "A" ;
    if (strcmp(str_1, str_2) == 0)
        printf("str_1 is equal to str_2. \n");
    else
        printf("str_1 is not equal to str_2. \n");
    if (strcmp(str_1, str_3) == 0)
       printf("str_1 is equal to str_3．\n");
    else
        printf("str_1 is not equalto str_3．\n");
}

