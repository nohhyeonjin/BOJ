#include <bits/stdc++.h>
#define MAX 501
#define INF 1e9
using namespace std;
int n,m;
vector<pair<int,int>> graph[MAX];
long long dist[MAX];
bool bellmanford(int start){
    dist[start]=0;
    for(int i=0;i<n;i++){
        for(int cur=1;cur<=n;cur++){
            for(int j=0;j<graph[cur].size();j++){
                int next=graph[cur][j].first;
                int cost=graph[cur][j].second;
                if(dist[cur]==INF) continue;
                if(dist[cur]+cost<dist[next]){
                    dist[next]=dist[cur]+cost;
                    if(i==n-1) return true;
                }
            }
        }
    }
    return false;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        graph[a].push_back({b,c});
    }
    fill(dist,dist+MAX,INF);
    bool negativeCycle=bellmanford(1);
    if(negativeCycle) printf("-1\n");
    else{
        for(int i=2;i<=n;i++){
            if(dist[i]==INF) printf("-1\n");
            else printf("%d\n",dist[i]);
        }
    }
}