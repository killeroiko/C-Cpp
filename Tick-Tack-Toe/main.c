#include <stdio.h>
#include <stdlib.h>
#include<time.h>

char table[3][3];

FILE *data;


void MultiPlayer()
{
    int i , j;
    for(i = 0; i < 3;i++){
        for(j = 0; j < 3;j++){
        }
    }

}

void startTable(){
    int i , j;
    for(i = 0; i < 3;i++){
            for(j = 0; j < 3;j++){
                table[i][j] = ' ';
                }
    }
    table[3][3] = '\0';

}
void showTable(){
    int i , j;
    for(i = 0; i < 3;i++){
            for(j = 0; j < 3;j++){
                printf(" %c ",table[i][j]);
                if(j < 2){
                        printf(" | ",table[i][j]);
                }
            }
            if(i < 2){
                    printf("\n____|_____|_____\n");
            }else{
                printf("\n    |     |     \n");
            }
    }
}

int Player1()
{
    int i , j,choice;
    printf("Player 1 pick a cell in the grid(Give a number 1-9)\n");
    scanf("%d",&choice);
    choice = choice - 1;
    for(i = 0;i < 3;i++){
        for(j = 0;j < 3;j++){
            if((i*3 + j) == choice){
                if(table[i][j] == ' '){
                   table[i][j] = 'X';
                   return choice + 1;
                }else{
                    return 10;
                }
            }
        }
    }
}

int Player2()
{
    int i , j,choice;
    printf("Player 2 pick a cell in the grid(Give a number 1-9)\n");
    scanf("%d",&choice);
    choice = choice - 1;
    for(i = 0;i < 3;i++){
        for(j = 0;j < 3;j++){
            if((i*3 + j) == choice){
                if(table[i][j] == ' '){
                   table[i][j] = 'O';
                   return choice;
                }else{
                    return 10;
                }
            }
        }
    }
}
int pcPlayer()
{
    int i , j,choice;
    printf("Player 2 pick a cell in the grid(Give a number 1-9)\n");
    choice = pcCard();
    for(i = 0;i < 3;i++){
        for(j = 0;j < 3;j++){
            if((i*3 + j) == choice){
                if(table[i][j] == ' '){
                   table[i][j] = 'O';
                   printf("%d\n",choice);
                   return choice;
                }else{
                    return 10;
                }
            }
        }
    }
}
int t = 0;
int pcCard(){
    int i , j;
    for(i = 0;i < 3;i++){
        for(j = 0;j < 3;j++){
                if(table[0][j] == table[1][j]){
                    if(table[0][j] == 'X' || table[0][j] == 'O'){
                           if(table[2][j] == ' '){
                                return 2*3 + j;
                           }
                    }
                }
                else if(table[0][j] == table[2][j]){
                    if(table[0][j] == 'X' || table[0][j] == 'O'){
                            if(table[1][j] == ' '){
                                return 1*3 + j;
                            }
                    }
                }
                else if(table[1][j] == table[2][j]){
                    if(table[1][j] == 'X' || table[1][j] == 'O'){
                            if(table[0][j] == ' '){
                                return 0*3 + j;
                            }
                    }
                }
        }
        if(table[i][0] == table[i][1]){
            if(table[i][0] == 'X' || table[i][0] == 'O'){
                if(table[i][2] == ' ')
                    return i*3 + 2;
            }
        }
        else if(table[i][1] == table[i][2]){
            if(table[i][1] == 'X' || table[i][1] == 'O'){
                if(table[i][0] == ' '){
                    return i*3 + 0;
                }
            }
        }
        else if(table[i][0] == table[i][2]){
            if(table[i][0] == 'X' || table[i][0] == 'O'){
                if(table[i][1] == ' '){
                    return i*3 + 1;
                }
            }
        }
    }
    if(table[0][0] == table[1][1]){
        if(table[0][0] == 'X' || table[0][0] == 'O'){
            if(table[2][2] == ' '){
                return 2*3 + 2;
            }
        }
    }
    else if(table[1][1] == table[2][2]){
        if(table[1][1] == 'X' || table[1][1] == 'O'){
            if(table[0][0] == ' '){
                return 0*3 + 0;
            }
        }
    }
   else if(table[0][0] == table[2][2]){
        if(table[0][0] == 'X' || table[0][0] == 'O'){
            if(table[1][1] == ' '){
                return 1*3 + 1;
            }
        }
    }
    if(table[0][2] == table[1][1]){
        if(table[0][2] == 'X' || table[0][2] == 'O'){
            if(table[2][0] == ' '){
                return 2*3 + 0;
            }
        }

    }
    else if(table[1][1] == table[2][0]){
        if(table[1][1] == 'X' || table[1][1] == 'O'){
            if(table[0][2] == ' '){
                return 0*3 + 2;
            }
        }
    }
    else if(table[0][2] == table[2][0]){
        if(table[0][2] == 'X' || table[0][2] == 'O'){
            if(table[1][1] == ' '){
                return 1*3 + 1;
            }
        }
    }
    int num = (rand() % 9) + 1;
    return num;
}

int result(){
    int i , j;
    for(i = 0;i < 3;i++){
        for(j = 0;j < 3;j++){
                if(table[0][j] == table[1][j] && table[0][j] == table[2][j] && table[1][j] == table[2][j]){
                    if(table[0][j] == 'X' || table[0][j] == 'O'){
                    return 1;
                    }
                }
        }
        if(table[i][0] == table[i][1] && table[i][1] == table[i][2] && table[i][0] == table[i][2] ){
            if(table[i][0] == 'X' || table[i][0] == 'O'){
            return 1;
            }
        }
    }
    if(table[0][0] == table[1][1] && table[1][1] == table[2][2] && table[0][0] == table[2][2]){
            if(table[0][0] == 'X' || table[0][0] == 'O'){
            return 1;
            }
    }else if(table[0][2] == table[1][1] && table[1][1] == table[2][0] && table[0][2] == table[2][0]){
        if(table[0][2] == 'X' || table[0][2] == 'O'){
        return 1;
        }

    }
}

int mainMenu(){
    int choice;
    printf("To continue select one of the following options:\n");
    printf("1. Multi Player(2 players)\n");
    printf("2. Single Player(Against the Computer)\n");
    printf("3. Stats\n");
    printf("4. Quit\n");
    scanf("%d",&choice);
    return choice;
}

int wins[6];
char *names[5];
char n0[50];
char n1[50];
char n2[50];
char n3[50];
char n4[50];

void loadNames(){

    int i;

    if ((data = fopen("data.txt","r"))!=NULL){
        fscanf(data,"%d",&wins[0]);
        fscanf(data,"%d",&wins[1]);
        fscanf(data,"%d",&wins[2]);
        fscanf(data,"%d",&wins[3]);
        fscanf(data,"%d",&wins[4]);
        fscanf(data,"%d",&wins[5]);
        fscanf(data,"%s",&n0);
        fscanf(data,"%s",&n1);
        fscanf(data,"%s",&n2);
        fscanf(data,"%s",&n3);
        fscanf(data,"%s",&n4);
        names[0] = n0;
        names[1] = n1;
        names[2] = n2;
        names[3] = n3;
        names[4] = n4;
        for(i = 0; i < 5; i++){
            printf("%s: %d wins\n",names[i],wins[i+1]);
        }
        fclose(data);

    }else
    printf("Error opening file\n");
}

void saveName(int pwins ,char *name){
    int i;
    if ((data = fopen("data.txt","w"))!=NULL){
        for (i = 0; i < 5;i++){
            if(pwins > wins[i+1]){
                wins[i+1] = pwins;
                names[i] = name;
                break;
            }
        }
        fprintf(data,"%d %d %d %d %d %s %s %s %s %s",wins[0],wins[1],wins[2],wins[3],wins[4],names[0],names[1],names[2],names[3],names[4]);
        fclose(data);
    }else{
        printf("Error opening file\n");
    }
    printf("Progress saved\n");
    system("PAUSE");

}

int main(int argc, char *argv[])
{
    int c ;
    int d = 0;
    int pwins = 0;
    int i;
    char name[50];
    printf("Welcome to Tic-Tac-Toe!\n");
    printf("Give your name: ");
    scanf("%s",&name);
    printf("Leader Board -Name-Wins- \n");
    loadNames();
    printf("Welcome: %s\n",name);
    system("PAUSE");
    while (c != 4){
        switch (mainMenu()){
            case 1: {
                c = 1;

                startTable();
                showTable();
                int i = 9;
                while(i > 0){

                        if(i == 0){
                            break;
                        }
                        d = Player1();
                        while(d < 0 || d > 9){
                                printf("You can't pick that one\n");
                                d = Player1();
                        }
                        showTable();
                        i--;
                        if(result() == 1){
                                printf("Player %s Wins!!\n",name);
                                pwins++;
                                printf("Wins: %d\n",pwins);
                                saveName(pwins,name);
                                break;
                        }
                        if(i == 0){
                            break;
                        }
                        d = Player2();
                        while(d < 0 || d > 9){
                                printf("You can't pick that one\n");
                                d = Player2();
                        }
                        showTable();
                        i--;
                        if(result() == 1){
                                printf("Player 2 Wins!!\n");
                                break;
                        }
                }
                printf("End Game\n");
                break;
            }

            case 2:{
                c = 2;

                startTable();
                showTable();
                int i = 9;
                while(i > 0){

                        if(i == 0){
                            break;
                        }
                        d = Player1();
                        while(d < 0 || d > 9){
                                printf("You can't pick that one\n");
                                d = Player1();
                        }
                        showTable();
                        i--;
                        if(result() == 1){
                                printf("Player %s Wins!!\n",name);
                                pwins++;
                                printf("Wins: %d\n",pwins);
                                saveName(pwins,name);
                                break;
                        }
                        if(i == 0){
                            break;
                        }
                        d = pcPlayer();
                        while(d < 0 || d > 9){
                                printf("You can't pick that one\n");
                                d = pcPlayer();
                        }
                        showTable();
                        i--;
                        if(result() == 1){
                                printf("Player 2 Wins!!\n");
                                break;
                        }
                }
                printf("End Game\n");
                break;
            }

            case 3:{
                c = 3;
                loadNames();
                break;
            }

            case 4:{
                c = 4;
                return 0;
            }
        }
    }
}
