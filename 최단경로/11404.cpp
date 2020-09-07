#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
int n,m;
int graph[101][101];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<101;i++) fill(graph[i],graph[i]+101,INF);
    for(int i=1;i<=n;i++) graph[i][i]=0;
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        graph[a][b]=min(graph[a][b],c);
    }
    for(int k=1;k<=n;k++){
        for(int a=1;a<=n;a++){
            for(int b=1;b<=n;b++){
                graph[a][b]=min(graph[a][b],graph[a][k]+graph[k][b]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(graph[i][j]==INF) printf("0 ");
            else printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}