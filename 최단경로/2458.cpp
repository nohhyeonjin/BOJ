#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
int n,m;
int dist[501][501];
int cnt[501];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) fill(dist[i],dist[i]+501,INF);
    for(int i=1;i<=n;i++) dist[i][i]=0;
    for(int i=0;i<m;i++){
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
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            if(dist[i][j]!=INF){
                cnt[i]++;
                cnt[j]++;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(cnt[i]==n-1) ans++;
    }
    printf("%d",ans);
}