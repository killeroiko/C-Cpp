#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Give int\n");
    int a,b,i=0;
    scanf("%d",&a);
    b = a;
    for (b;b>0;b=b/10)
    {
        i++;
    }
    printf("%d Digits\n",i);
    int big=0,small=9;
    b = a;
    int c;
    for (b;b>0;b=b/10){
            c = b %10;
     if (c > big)
     {
        big = c;
     }
    }
    b = a;
    for (b;b>0;b=b/10){
            c = b %10;
     if (c < small)
     {
        small = c;
     }
    }
    printf("big %d , Small %d\n",big,small);
    c = (big+small)/2;
    printf("The median is: %d",c);
    return 0;
}
