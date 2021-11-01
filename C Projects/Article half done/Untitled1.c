#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char text[10000];
char words[10000];
char sentences[10000];
char paragraphs[10000];

void save(){
    int w = 1 , s = 1, p = 1,t = 1,i;

    for(i = 0;i < sizeof(words);i++){
        words[i] = '\0';
    }
    for(i = 0;i < sizeof(sentences);i++){
        sentences[i] = '\0';
    }
    for(i = 0;i < sizeof(paragraphs);i++){
        paragraphs[i] = '\0';
    }

    if(text[0]!= ' ' || text[0]!='\0'){

        words[0] = text[0];
        sentences[0] = text[0];
        paragraphs[0] = text[0];

        while(text[t]!='\0'){
            if(text[t] == ' ' || text[t] == '.' || text[t] == '!' || text[t] == '?' || text[t] == ';' || text[t] =='\n'){
                words[w] = '+';
                w++;
            }else{
                words[w] = text[t];
                w++;
            }
            if(text[t] == '.' || text[t] == '!' || text[t] == '?' || text[t] == ';' || text[t] =='\n'){
                sentences[s] = '+';
                s++;
            }else{
                sentences[s] = text[t];
                s++;
            }
            if(text[t] =='\n'){
                paragraphs[p] = '+';
                p++;
            }else{
                paragraphs[p] = text[t];
                p++;
            }
            t++;
        }
    }
}

void ap(){
    int w = 1 , s = 1, p = 1,i;

    for(i = 0;i < sizeof(words);i++){
        words[i] = '\0';
    }
    for(i = 0;i < sizeof(sentences);i++){
        sentences[i] = '\0';
    }

    if(paragraphs[0]!= ' ' || paragraphs[0]!='\0'){
        words[0] = paragraphs[0];
        sentences[0] = paragraphs[0];
        while(paragraphs[p]!='\0'){
            if(paragraphs[p] == ' ' || paragraphs[p] == '.' || paragraphs[p] == '!' || paragraphs[p] == '?' || paragraphs[p] == ';' || paragraphs[p]=='\n'){
                words[w] = '+';
                w++;
            }else{
                words[w] = paragraphs[p];
                w++;
            }
            if(paragraphs[p] == '.' || paragraphs[p] == '!' || paragraphs[p] == '?' || paragraphs[p] == ';' || paragraphs[p] =='\n'){
                sentences[s] = '+';
                s++;
            }else{
                sentences[s] = paragraphs[p];
                s++;
            }
            p++;
        }
    }
}

void fw(){
    int w = 0, i = 0, a = 0 , n = 0 ;
    char temp[100]="";
    char wr[10000][100]={""};

    while(words[w]!='\0'){

        if(words[w] == '+' && words[w+1]!='+'){
            for(n = 0; n < a+1; n++){
                if(!strcmp(wr[n],temp)){
                    break;
                }else if(wr[n][0] == '\0'){
                    strcat(wr[n],temp);
                    a++;
                    break;
                }
            }
            for(i = 0;i < 100;i++){
                temp[i] = '\0';
            }
            i=0;
        }else{
            temp[i] = words[w];
            i++;
        }
        w++;
    }

    for(n = 0; n < a+1; n++){
        if(!strcmp(wr[n],temp)){
            break;
        }else if(wr[n][0] == '\0'){
            strcat(wr[n],temp);
            a++;
            break;
        }
    }
    for(i = 0;i < 100;i++){
        temp[i] = '\0';
    }
    i=0;

    for(n = 0;n < a;n++){
        if(strstr(wr[n],text)){
            printf("%s\n",wr[n]);
        }
    }
}
void fs(){
    int s = 0, i = 0;
    char temp[100] = "";
    char st[10000] = "";

    if(text[0]!=' ' || text[0]!='\0'){

        while(sentences[s]!='\0'){
            if(sentences[s] == '+'){
                if(sentences[s+1]!='+'){
                    if(strstr(temp,text)!=NULL){
                        if(strstr(st,temp)!=NULL){
                            strcat(st,temp);
                        }else{
                            printf("%s\n",temp);
                            strcat(st,temp);
                            strcat(st," ");
                        }
                    }
                    for(i = 0;i < 100;i++){
                        temp[i] = '\0';
                    }
                    i = 0;
                }
            }else{
                temp[i] = sentences[s];
                i++;
            }
            s++;
        }
        if(strstr(temp,text)!=NULL){
            if(strstr(st,temp)!=NULL){
                strcat(st,temp);
            }else{
                printf("%s\n",temp);
                strcat(st,temp);
                strcat(st," ");
            }
        }
    }
}
void fp(){
    int p = 0, i = 0;
    char temp[100] = "";
    char pr[10000] = "";

    if(text[0]!=' ' || text[0]!='\0'){

        while(paragraphs[p]!='\0'){
            if(paragraphs[p] == '+'){
                if(paragraphs[p+1]!='+'){
                    if(strstr(temp,text)!=NULL){
                        if(strstr(pr,temp)!=NULL){
                            strcat(pr,temp);
                        }else{
                            printf("%s\n",temp);
                            strcat(pr,temp);
                            strcat(pr," ");
                        }
                    }
                    for(i = 0;i < 100;i++){
                        temp[i] = '\0';
                    }
                    i = 0;
                }
            }else{
                temp[i] = paragraphs[p];
                i++;
            }
            p++;
        }
        if(paragraphs[p+1]!='+'){
            if(strstr(temp,text)!=NULL){
                if(strstr(pr,temp)!=NULL){
                    strcat(pr,temp);
                }else{
                    printf("%s\n",temp);
                    strcat(pr,temp);
                    strcat(pr," ");
                }
            }
        }
    }
}

void owf(){
    int w = 0, i = 0, a = 0 , n = 0 ;
    char temp[100]="";
    char wr[10000][100]={""};
    char k = '1';

    while(words[w]!='\0'){

        if(words[w] == '+' && words[w+1]!='+'){
            for(n = 0; n < a+1; n++){
                if(wr[n][0] != '\0'){
                    char temp2[100] = "";
                    int t1;
                    for(t1 = 0; t1 < strlen(temp);t1++){
                        temp2[t1] = wr[n][t1];
                    }
                    if(!strcmp(temp2,temp)){
                        k = wr[n][strlen(wr[n])-2];
                        k++;
                        wr[n][strlen(wr[n])-2] = k;
                        break;
                    }
                }else if(wr[n][0] == '\0'){
                    k = '1';
                    strcat(wr[n],temp);
                    strcat(wr[n]," [");
                    wr[n][strlen(wr[n])] = k;
                    strcat(wr[n],"]");
                    a++;
                    break;
                }
            }
            for(i = 0;i < 100;i++){
                temp[i] = '\0';
            }
            i=0;
        }else{
            temp[i] = words[w];
            i++;
        }
        w++;
    }

    for(n = 0; n < a+1; n++){
        if(wr[n][0] != '\0'){
            char temp2[100] = "";
            int t1;
            for(t1 = 0; t1 < strlen(temp);t1++){
                temp2[t1] = wr[n][t1];
            }
            if(!strcmp(temp2,temp)){
                k = wr[n][strlen(wr[n])-2];
                k++;
                wr[n][strlen(wr[n])-2] = k;
                break;
            }
        }else if(wr[n][0] == '\0'){
            k = '1';
            strcat(wr[n],temp);
            strcat(wr[n]," [");
            wr[n][strlen(wr[n])] = k;
            strcat(wr[n],"]");
            a++;
            break;
        }
    }
    for(i = 0;i < 100;i++){
        temp[i] = '\0';
    }
    i=0;


    int j;
    for(i = 0; i < a - 1; i++){
        for(j = 0 ; j < a - i - 1; j++){
            if(wr[j][strlen(wr[j])-2] < wr[j+1][strlen(wr[j+1])-2]){
                strcpy(temp,wr[j]);
                strcpy(wr[j],wr[j+1]);
                strcpy(wr[j+1],temp);
            }else if(wr[j][strlen(wr[j])-2] == wr[j+1][strlen(wr[j+1])-2]){
                if(strcmp(wr[j],wr[j+1]) == 1){
                    strcpy(temp,wr[j]);
                    strcpy(wr[j],wr[j+1]);
                    strcpy(wr[j+1],temp);
                }
            }
        }
    }

    for(n = 0;n < a;n++){
        printf("%s\n",wr[n]);
    }
}

void owl(){
    int w = 0, i = 0, a = 0 , n = 0 ;
    char temp[100]="";
    char wr[10000][100]={""};

    while(words[w]!='\0'){

        if(words[w] == '+' && words[w+1]!='+'){
            for(n = 0; n < a+1; n++){
                if(!strcmp(wr[n],temp)){
                    break;
                }else if(wr[n][0] == '\0'){
                    strcat(wr[n],temp);
                    a++;
                    break;
                }
            }
            for(i = 0;i < 100;i++){
                temp[i] = '\0';
            }
            i=0;
        }else{
            temp[i] = words[w];
            i++;
        }
        w++;
    }

    for(n = 0; n < a+1; n++){
        if(!strcmp(wr[n],temp)){
            break;
        }else if(wr[n][0] == '\0'){
            strcat(wr[n],temp);
            a++;
            break;
        }
    }
    for(i = 0;i < 100;i++){
        temp[i] = '\0';
    }
    i=0;


    int j;
    for(i = 0; i < a - 1; i++){
        for(j = 0 ; j < a - i - 1; j++){
            if(strlen(wr[j]) > strlen(wr[j+1])){
                strcpy(temp,wr[j]);
                strcpy(wr[j],wr[j+1]);
                strcpy(wr[j+1],temp);
            }else if(strlen(wr[j]) == strlen(wr[j+1])){
                if(strcmp(wr[j],wr[j+1]) == 1){
                    strcpy(temp,wr[j]);
                    strcpy(wr[j],wr[j+1]);
                    strcpy(wr[j+1],temp);
                }
            }
        }
    }

    for(n = 0;n < a;n++){
        printf("%s [%d]\n",wr[n],strlen(wr[n]));
    }
}

void check(){
    int w = 0;
    int i = 1;

    printf("Word %d: ",i);
    i++;
    while(words[w]!='\0'){
        if(words[w] == '+'){
            if(words[w+1]!='+'){
                printf("\nWord %d: ",i);
                i++;
           }
        }else{
           printf("%c",words[w]);
        }
        w++;
    }
    printf("\n");

    int s = 0;
    i = 1;
    printf("Sentence %d: ",i);
    i++;
    while(sentences[s]!='\0'){
        if(sentences[s] == '+'){
            if(sentences[s+1] != '+'){
                printf("\nSentence %d: ",i);
                i++;
            }
        }else{
           printf("%c",sentences[s]);
        }
        s++;
    }
    printf("\n");

    int p = 0;
    i = 1;
    printf("Paragraph %d: ",i);
    i++;
    while(paragraphs[p]!='\0'){
        if(paragraphs[p] == '+'){
            if(paragraphs[p+1] != '+'){
                printf("\nParagraph %d: ",i);
                i++;
            }
        }else{
           printf("%c",paragraphs[p]);
        }
        p++;
    }
    printf("\n");
}

int main()
{
    char command[3];
    //printf("Give a Text: ");
    //gets(&text);
    //save();
    //check();
    //printf("Give Your Command: ");
    gets(&command);
    while(strcmp(command,"qt")){
        if(!strcmp(command,"ap")){
                //printf("Give Your Paragraph: ");
                gets(&paragraphs);
                ap();
        }
        else if(!strcmp(command,"fw")){
                //printf("Give Your Text: ");
                gets(&text);
                fw();
        }
        else if(!strcmp(command,"fs")){
                //printf("Give Your Text: ");
                gets(&text);
                fs();
        }
        else if(!strcmp(command,"fp")){
                //printf("Give Your Text: ");
                gets(&text);
                fp();
        }
        else if(!strcmp(command,"owf")){
                owf();
        }
        else if(!strcmp(command,"owl")){
                owl();
        }
        else { printf("Invalid Command\n"); }
        printf("Enter New Command: ");
        gets(&command);
    }
    return 0;
}

/////////////////
void save(){
    int w = 1 , s = 1, p = 1,t = 1,i;

    for(i = 0;i < sizeof(words);i++){
        words[i] = '\0';
    }
    for(i = 0;i < sizeof(sentences);i++){
        sentences[i] = '\0';
    }
    for(i = 0;i < sizeof(&paragraphs);i++){
        paragraphs[i] = '\0';
    }

    if(&text[0]!= ' ' || &text[0]!='\0'){

        words[0] = &text[0];
        sentences[0] = &text[0];
        paragraphs[0] = &text[0];

        while(&text[t]!='\0'){
            if(&text[t] == ' ' || &text[t] == '.' || &text[t] == '!' || &text[t] == '?' || &text[t] == ';' || &text[t] =='\n'){
                words[w] = '+';
                w++;
            }else{
                words[w] = &text[t];
                w++;
            }
            if(&text[t] == '.' || &text[t] == '!' || &text[t] == '?' || &text[t] == ';' || &text[t] =='\n'){
                sentences[s] = '+';
                s++;
            }else{
                sentences[s] = &text[t];
                s++;
            }
            if(&text[t] =='\n'){
                paragraphs[p] = '+';
                p++;
            }else{
                paragraphs[p] = &text[t];
                p++;
            }
            t++;
        }
    }
}
