#include <iostream>
using namespace std;
int n,m;
int graph[101][101];    //무거움(1), 가벼움(-1), 모름(0)
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        graph[a][b]=1;
        graph[b][a]=-1;
    }
    for(int k=1;k<=n;k++){
        for(int a=1;a<=n;a++){
            for(int b=1;b<=n;b++){
                if(graph[a][k]==1&&graph[k][b]==1) graph[a][b]=1;
                if(graph[a][k]==-1&&graph[k][b]==-1) graph[a][b]=-1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        int ans=0;
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            if(graph[i][j]==0) ans++;
        }
        printf("%d\n",ans);
    }
}