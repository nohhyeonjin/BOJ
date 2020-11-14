#include <bits/stdc++.h>
#define MAX 101
#define INF 1e9
using namespace std;
int n,m;
int minVal=INF;
int ans=INF;
int graph[MAX][MAX];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<MAX;i++) fill(graph[i],graph[i]+MAX,INF);
    for(int i=1;i<=n;i++) graph[i][i]=0;
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        graph[a][b]=1;
        graph[b][a]=1;
    }
    for(int k=1;k<=n;k++){
        for(int a=1;a<=n;a++){
            for(int b=1;b<=n;b++){
                graph[a][b]=min(graph[a][b],graph[a][k]+graph[k][b]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        int val=0;
        for(int j=1;j<=n;j++){
            if(graph[i][j]==INF) continue;
            val+=graph[i][j];
        }
        if(val<minVal){
            minVal=val;
            ans=i;
        }
    }
    printf("%d",ans);
}