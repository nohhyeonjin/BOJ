#include <iostream>
int main(){
    int t;
    char num[101];
    int sum=0;

    scanf("%d",&t);
    scanf("%s",num);
    for(int i=0;i<t;i++){
        sum+=num[i]-'0';
    }
    printf("%d",sum);
} 