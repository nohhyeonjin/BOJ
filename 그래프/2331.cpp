#include <stdio.h>
#include <cmath>
int visited[296000];
int a, p;
void dfs(int num){
    visited[num]++;
    if(visited[num]==3) return;
    int sum=0;
    while(num){
        sum+=(int)floor(pow(num%10,p));
        num/=10;
    }
    dfs(sum);
}
int main(){
    int answer=0;
    scanf("%d %d",&a,&p);
    dfs(a);
    for(int i=0;i<296000;i++){
        if(visited[i]==1) answer++;
    }
    printf("%d",answer);
}