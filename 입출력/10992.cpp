#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    //첫줄
    for(int i=0;i<n-1;i++) printf(" ");
    printf("*\n");
    //중간줄
    for(int i=0;i<n-2;i++){
        for(int j=0;j<n-2-i;j++) printf(" ");
        printf("*");
        for(int j=0;j<2*i+1;j++) printf(" ");
        printf("*\n");
    }
    //마지막줄
    if(n>1){
        for(int i=0;i<2*n-1;i++) printf("*");
    }
}