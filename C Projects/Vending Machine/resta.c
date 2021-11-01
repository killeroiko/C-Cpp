#include <stdio.h>
#include <stdlib.h>


int main()

  {
    printf("Give the money paid(eg. 0.75)\n");
    int c2=0,c1=0,c50=0,c20=0,c10=0,c5=0;
    float m,c;
    scanf("%f",&m);

    c = m - 0.75;
    printf("Your change are:%.2f\n",c);

    if (c>=2)
    {
     c2++;
     c = c- 2;
     printf("%d *2\n",c2);
    }
     if (c>=1)
    {
     c=c-1;
     c1++;
     printf("%d *1\n",c1);
    }
   if (c>=0.50)
    {
     c=c-0.50;
     c50++;
     printf("%d *0.50\n",c50);
    }
    if (c>=0.20)
    {
     c=c-0.20;
     c20++;
     printf("%d *0.20\n",c20);
    }
      if (c>=0.10)
     {
     c=c-0.10;
     c10++;
     printf("%d *0.10\n",c10);
    }
    if (c>=0.05)
    {
     c=c-0.05;
     c5++;
     printf("%d *0.05\n",c5);
    }

  return 0;
  }
