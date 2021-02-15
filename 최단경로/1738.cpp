#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
int n,m;
vector<pair<int,int>> graph[101];
long long table[101];
int route[101];
set<int> cycleVertex;
bool cycle;
bool visited[101];
bool bfs(int a){
    fill(visited,visited+101,false);
    queue<int> q;
    q.push(a);
    visited[a]=true;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int i=0;i<graph[cur].size();i++){
            int next=graph[cur][i].first;
            if(next==n) return true;
            if(!visited[next]){
                q.push(next);
                visited[next]=true;
            }
        }
    }
    return false;
}
bool bellmanford(){
    table[1]=0;
    for(int i=0;i<n;i++){
        for(int cur=1;cur<=n;cur++){
            for(int j=0;j<graph[cur].size();j++){
                int next=graph[cur][j].first;
                int cost=-graph[cur][j].second;
                if(table[cur]==INF) continue;
                if(table[cur]+cost<table[next]){
                    table[next]=table[cur]+cost;
                    if(i==n-1){
                        cycle=true;
                        cycleVertex.insert(cur);
                    }
                }
            }
        }
    }
    if(cycle){
        set<int>::iterator iter=cycleVertex.begin();
        for(iter;iter!=cycleVertex.end();iter++){
            if(bfs(*iter)) return true;
        }
    }
    fill(table,table+101,INF);
    table[1]=0;
    for(int i=0;i<n-1;i++){
        for(int cur=1;cur<=n;cur++){
            for(int j=0;j<graph[cur].size();j++){
                int next=graph[cur][j].first;
                int cost=-graph[cur][j].second;
                if(table[cur]==INF||cycleVertex.count(cur)!=0) continue;
                if(table[cur]+cost<table[next]){
                    table[next]=table[cur]+cost;
                    route[next]=cur;
                }
            }
        }
    }
    return false;
}
void printRoute(int n){
    if(n!=1) printRoute(route[n]);
    printf("%d ",n);
    if(n==1) return;
}
int main(){
    scanf("%d %d",&n,&m);
    fill(table,table+101,INF);
    for(int i=0;i<m;i++){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        graph[u].push_back({v,w});
    }
    bool negativeCycle = bellmanford();
    if(negativeCycle) printf("-1");
    else printRoute(n);
}