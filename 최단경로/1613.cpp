#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
int n,k;
int dist[401][401];
int main(){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++) fill(dist[i],dist[i]+401,INF);
    for(int i=1;i<=n;i++) dist[i][i]=0;
    for(int i=0;i<k;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        dist[a][b]=1;
    }
    for(int k=1;k<=n;k++){
        for(int a=1;a<=n;a++){
            for(int b=1;b<=n;b++){
                dist[a][b]=min(dist[a][b],dist[a][k]+dist[k][b]);
            }
        }
    }
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        if(dist[a][b]==INF&&dist[b][a]==INF) printf("0\n");
        if(dist[a][b]!=INF&&dist[b][a]==INF) printf("-1\n");
        if(dist[a][b]==INF&&dist[b][a]!=INF) printf("1\n");
    }
}