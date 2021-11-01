#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
    printf("Give a decimal number\n");
    int r,b=0,m,i=1;
    scanf("%d",&r);
    while (r!=0)
    {
     m = r%2;
     r /= 2;
     b += m*i;
     i *=10;
     }
     printf("%d",b);

    return 0;
}
