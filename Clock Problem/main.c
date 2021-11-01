#include <stdio.h>
#include <stdlib.h>

int main()
{
    int h,m,s,a,b;
    printf("Give the hour, minutes and seconds: \n");
    scanf("%d %d %d",&h,&m,&s);
    printf("Give two points on the clock: ");
    scanf("%d %d",&a,&b);
    m = m/5;
    s = s/5;
    for (a;a == b; a++)
            {
                if (a = h || a = m || a = s)
                {
                    printf("From a to b NO");
                }
            }
            for (a;a == b; a--)
            {
                if (a = h || a = m || a = s)
                {
                    printf("From b to a NO");
                    return 0;
                }
            }
    printf("YES");
    return 0;
}
