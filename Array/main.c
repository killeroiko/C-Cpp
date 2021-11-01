#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fill(int k,int a[]){
    int i;
    if(!k){
        printf("Array Filled \n");
        return a;
    }
    else{
        scanf("%d",&i);
        *a = i;
        return fill(k-1,a+1);
    }
}

void show(int k,int a[]){
    if(!k){
        printf("End of Array \n");
        return 0;
    }
    else{
        printf("%d ",*a);
        return show(k-1,a+1);
    }
}

int number(int k,int a[],int b[] , int c[]){
    if(!k){
        return c;
    }
    else{
        *c = *a + *b;
        return number(k-1,a+1,b+1,c+1);
    }
}

int main(int argc , char *argv[])
{
    int k;
    int *a1,*a2,*a3;
    printf("Give the size: ");
    scanf("%d",&k);
    a1 = (int *) calloc(k+1,sizeof(int));
    a2 = (int *) calloc(k+1,sizeof(int));
    a3 = (int *) calloc(k+1,sizeof(int));
    printf("Two arrays of size %d made \n",k);
    printf("Fill The Array Number 1: ");
    fill(k,a1);
    printf("Fill The Array Number 2: ");
    fill(k,a2);
    number(k,a1,a2,a3);
    printf("Your new Array is: \n");
    show(k,a3);
    return 0;
}
