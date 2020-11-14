#include <bits/stdc++.h>
#define MAX 501
#define INF 1e9
using namespace std;
int n,m,w;
int dist[MAX];
bool bellmanford(vector<vector<pair<int,int>>> graph, int start){
    fill(dist,dist+MAX,INF);
    dist[start]=0;
    for(int i=0;i<n;i++){
        for(int cur=1;cur<=n;cur++){
            for(int j=0;j<graph[cur].size();j++){
                int next=graph[cur][j].first;
                int cost=graph[cur][j].second;
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
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&n,&m,&w);
        vector<vector<pair<int,int>>> graph;
        graph.resize(n+1);
        int a,b,c;
        for(int i=0;i<m;i++){
            scanf("%d %d %d",&a,&b,&c);
            graph[a].push_back({b,c});
            graph[b].push_back({a,c});
        }
        for(int i=0;i<w;i++){
            scanf("%d %d %d",&a,&b,&c);
            graph[a].push_back({b,-c});
        }
        bool negativeCycle=bellmanford(graph,1);
        if(negativeCycle) printf("YES\n");
        else printf("NO\n");
    }
}