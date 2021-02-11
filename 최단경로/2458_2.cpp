#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
int n,m,ans;
int dist[501][501];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        dist[a][b]=1;
    }
    for(int k=1;k<=n;k++){
        for(int a=1;a<=n;a++){
            for(int b=1;b<=n;b++){
                if(dist[a][k]==1&&dist[k][b]==1) dist[a][b]=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(dist[i][j]==1||dist[j][i]==1) cnt++;
        }
        if(cnt==n-1) ans++;
    }
    printf("%d",ans);
}