#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 100;
    printf("System Operation: Initialize\n");
    while(a != 0){
        printf("User Input required (Select existing User): \n");
        printf("1: Giannhs\n");
        printf("2: Mistos\n");
        printf("3: Alexis\n");
        printf("4: Thodoros\n");
        scanf("%d",&a);
        if(a == 1){
            printf("Hello Giannhs\n");
            a = 0;
        }
        else if(a == 2){
            printf("Hello Mitsos\n");
            a = 0;
        }
        else if(a == 3){
            printf("Alexi kses kati?\n");
            int b = 5;
            while(b != 0){
                printf("Select Answer(currently available: 1)\n");
                printf("1: Ti?\n");
                scanf("%d",&b);
                if(b == 1){
                    printf("gamiese\n");
                    b = 0;
                    a = 0;
                }
            }
        }
        else if(a == 4){
            printf("Hello Thodoros\n");
            a = 0;
        }
        else{
            printf("User not Found\n");
        }
    }
        printf("System Process: Termination\n");
    return 0;
}
