#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
    printf("Give the sides of the triangle");
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    int k1,k2,max=a;
    k1=b;
    k2=c;
    if (b>max)
    {
     max = b;
     k1=a;
     k2=c;
    }
    else if (c>max)
    {
     max=c;
     k1=a;
     k2=b;
    }
    if (max*max == k1*k1 + k2*k2)
    {
     printf("Right Triangle");
    }
    else if (max*max > k1*k1 +k2*k2)
    {
     printf("Obtuse Triangle");
    }
    else if (max*max < k1*k1 + k2*k2)
    {
     printf("Acute Triangle");
    }
   return 0;
}
