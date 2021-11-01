#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(int argc, char *argv[])
{
    int n=0;
    printf("Pws se lene?\n");
    char str[100];
    char c;
    while(c != 13){
        if(n < 100 && c != 13){
            c = getch();
            str[n] = c;
            putch(str[n]);
            n++;
        }
        else{
            printf("/nStamataaaaaa");
            c = 13;
        }
    }

    printf("\n");

    int m = n;
    char name[n];
    do{
        name[n] = str[n];
        n--;
    }while(n >= 0);

    char alexis[] = "Alexi";

    int counter = 0;

    if(m == 6){
        m = 0;
        while(m < 6){
            if(alexis[m] == name[m]){
                counter++;
            }
            m++;
        }
        if(counter == 5){
            printf("Alexi kses kati?\n");
            n = 0;
            c = 1 ;

            while(c != 13){
                if(n < 100 && c != 13){
                    c = getch();
                    str[n] = c;
                    putch(str[n]);
                    n++;
                }
                else{
                    printf("/nStamataaaaaa");
                    c = 13;
                }
            }
            m = n;
            char ans[n];
            do{
                ans[n] = str[n];
                n--;
            }while(n >= 0);

            char ti[] = "Ti?";

            if(m == 4){
                counter = 0;
                m = 0;
                while(m < 4){
                    if(ti[m] == ans[m]){
                        counter++;
                    }
                    m++;
                }
                if(counter == 3){
                    printf("\nGamieseee");
                }
            }
        }
        else{
        n = 0;

        char kati[] = " kses kati?";

        while(n < m + 11){
            if(n < m){
                printf("%c",name[n]);
            }
            else{
                printf("%c",kati[n-m]);
            }
            n++;
        }
        n = 0;
            c = 1 ;

            while(c != 13){
                if(n < 100 && c != 13){
                    c = getch();
                    str[n] = c;
                    putch(str[n]);
                    n++;
                }
                else{
                    printf("/nStamataaaaaa");
                    c = 13;
                }
            }
            m = n;
            char ans[n];
            do{
                ans[n] = str[n];
                n--;
            }while(n >= 0);

            char ti[] = "Ti?";

            if(m == 4){
                counter = 0;
                m = 0;
                while(m < 4){
                    if(ti[m] == ans[m]){
                        counter++;
                    }
                    m++;
                }
                if(counter == 3){
                    printf("\nGamieseee");
                }
            }
}
    }else{
        n = 0;
        printf("\nGeia sou ");
        while(n < m){
            putch(name[n]);
            n++;
        }
    }
    return 0;
}
