#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int d1,d2,y1,y2,m1,m2;
    printf("Dwse 2 hmerominies(Dwse tis swstes giati bariemai na elenxw)\n");
    printf("Hm 1. Mera: ");
    scanf("%d",&d1);
    printf("Hm 1. Mhnas: ");
    scanf("%d",&m1);
    printf("Hm 1. Xronia: ");
    scanf("%d",&y1);
    printf("Hm 2. Mera: ");
    scanf("%d",&d2);
    printf("Hm 2. Mhnas: ");
    scanf("%d",&m2);
    printf("Hm 2. Xronia: ");
    scanf("%d",&y2);
    m1 = m1 * 30;
    m2 = m2 * 30;
    y1 = y1 * 365;
    y2 = y2 * 365;
    int date1 = d1 + m1 + y1;
    int date2 = d2 + m2 + y2;
    if(date1 > date2){
        printf("Exoyn %d meres diafora",date1 - date2);
    }
    else
        printf("Exoyn %d meres diafora",date2 - date1);

    return 0;
}
