#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

int main(int argc , char *argv[])
{
    char s[30];
    char s1[] = "alexi";
    char s2[] = "Alexi";
    char ans1[] = "Ti?";
    char ans2[] = "ti?";
    char ans3[] = "ti";
    char ans4[] = "Ti";
    char ase[] = "ASE MAS KOUKLITSA MOU";
    printf("Pws se lene? ");
    gets(s);
    if(strcmp(s,s2) && strcmp(s,s1)){
        printf("\n%s kses kati? ",s);
        gets(s);
        while(strcmp(s,ans1) && strcmp(s,ans2) && strcmp(s,ans3) && strcmp(s,ans4)){
            printf("\nDen se katalabenw, apanthse moy kses kati? ");
            gets(s);
        }
        printf("\nO Alexis\n");
        system("pause");
        printf("\nGamieteeeeee\n");
    }else{
        printf("\n%s kses kati? ",s);
        gets(s);
        while(strcmp(s,ans1) && strcmp(s,ans2) && strcmp(s,ans3) && strcmp(s,ans4) && strcmp(s,ase)){
            printf("\nDen se katalabenw, apanthse moy kses kati? ");
            gets(s);
        }
        if(strcmp(s,ase)){
            printf("\nGamieseeeeee\n");
        }
    }
    system("pause");
    return 0;
}
