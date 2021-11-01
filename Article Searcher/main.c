#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void save(char* text,char* words,char* sentences,char* paragraphs){
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

void ap(char* text,char* words,char* sentences,char* paragraphs){
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

void fw(char* text,char* words,char* sentences,char* paragraphs){
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
        printf("%s\n",wr[n]);
    }
}
void fs(char* text,char* words,char* sentences,char* paragraphs){
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
void fp(char* text,char* words,char* sentences,char* paragraphs){
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

void owf(char* text,char* words,char* sentences,char* paragraphs){
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

void owl(char* text,char* words,char* sentences,char* paragraphs){
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
        printf("%s [%ld]\n",wr[n],strlen(wr[n]));
    }
}

int main()
{
    char *text,*words,*sentences,*paragraphs;

    text = (char *) malloc(10000*sizeof(char));
    words = (char *) malloc(10000*sizeof(char));
    sentences = (char *) malloc(10000*sizeof(char));
    paragraphs = (char *) malloc(10000*sizeof(char));

    char *command;
    command = (char *) malloc(3*sizeof(char));

    printf("Give text\n");
    scanf(" %[^\n]s",text);
    save(text,words,sentences,paragraphs);
    printf("Give command\n");
    scanf(" %[^\n]s",command);
    while(strcmp(command,"qt")){
        if(!strcmp(command,"ap")){
                printf("Give Your Paragraph: ");
                scanf(" %[^\n]s",paragraphs);
                ap(text,words,sentences,paragraphs);
        }
        else if(!strcmp(command,"fw")){
                printf("Give Your Text: ");
                scanf(" %[^\n]s",text);
                fw(text,words,sentences,paragraphs);
        }
        else if(!strcmp(command,"fs")){
                printf("Give Your Text: ");
                scanf(" %[^\n]s",text);
                fs(text,words,sentences,paragraphs);
        }
        else if(!strcmp(command,"fp")){
                printf("Give Your Text: ");
                scanf(" %[^\n]s",text);
                fp(text,words,sentences,paragraphs);
        }
        else if(!strcmp(command,"owf")){
                owf(text,words,sentences,paragraphs);
        }
        else if(!strcmp(command,"owl")){
                owl(text,words,sentences,paragraphs);
        }
        else { printf("Invalid Command\n"); }
        printf("Enter New Command: ");
        scanf(" %[^\n]s",command);
    }

    free(text);
    free(words);
    free(sentences);
    free(paragraphs);
    return 0;
}
