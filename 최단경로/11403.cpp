#include <bits/stdc++.h>
using namespace std;
int graph[101][101];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) scanf("%d",&graph[i][j]);
    }
    for(int k=1;k<=n;k++){
        for(int a=1;a<=n;a++){
            for(int b=1;b<=n;b++){
               if(graph[a][k]==1&&graph[k][b]==1) graph[a][b]=1; 
            } 
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) printf("%d ",graph[i][j]);
        printf("\n");
    }
}