#include <stdio.h>
#include <stdlib.h>

int tempreture(t)
int t;
{
    printf("Give a temperature: \n");
    scanf("%d",&t);
    if (t < 20)
    {
        printf("Its Cold");
    }
    else if (t>=20 && t < 30)
    {
        printf("Its Good");
    }
    else if (t>=30)
    {
        printf("Its Hot");
    }
}

int main()
{
    int a;
    a = tempreture(a);
    return 0;
}
