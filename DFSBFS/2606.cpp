#include <bits/stdc++.h>
using namespace std;
int c,p,ans;
int graph[101][101], visited[101];
void dfs(int num){
    visited[num]=1;
    for(int i=1;i<=c;i++){
        if(graph[num][i]==1&&visited[i]==0){
            ans++;
            dfs(i);
        }
    }
}
int main(){
    scanf("%d %d",&c,&p);
    for(int i=0;i<p;i++){
        int first, second;
        scanf("%d %d",&first,&second);
        graph[first][second]=graph[second][first]=1;
    }
    dfs(1);
    printf("%d",ans);
}