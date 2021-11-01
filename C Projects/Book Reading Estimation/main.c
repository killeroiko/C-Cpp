#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Give the pages, the pages read in the first day,the max number of pages bob can read a day,the number of extra pages per day and the pages he has to read again:\n");
    int c,v0,v1,a,i,d=0;
    scanf("%d %d %d %d %d",&c,&v0,&v1,&a,&i);
    if((c==0)||(v0==0)||(v1==0)||(a==0)||(i==0))
    {
        printf("Wrong Format");
    }
    else{
        c = c - v0;
        d++;
        while(c>0){
            c = c - (v0 + a + i);
            d++;
            if ((v0 + a +i) <= v1){a+=a;}
        }
        printf("He read the book in: %d days",d);
    }
    return 0;
}
