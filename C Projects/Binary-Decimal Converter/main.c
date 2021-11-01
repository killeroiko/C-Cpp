#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    printf("Give a Binary number\n");
    int b,i=0,d=0;
    scanf("%d",&b);
    while (b)
    {
        d=d+pow(2,i)*(b%10);
        b/=10;
        i++;
    }
    printf("%d",d);
    return 0;
}
