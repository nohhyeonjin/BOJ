#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
int n,m;
int s,e;
vector<pair<int,int>> graph[101];
int earn[101];
long long table[101];
bool visited[101];
bool canGo(int a,int b){
    visited[a]=true;
    queue<int> q;
    q.push(a);
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int i=0;i<graph[cur].size();i++){
            int next=graph[cur][i].first;
            if(next==b) return true;
            if(!visited[next]){
                visited[next]=true;
                q.push(next);
            }
        }
    }
    return false;
}
bool bellmanford(int v){
    table[v]=-earn[v];
    for(int i=0;i<n-1;i++){
        for(int cur=0;cur<n;cur++){
            for(int j=0;j<graph[cur].size();j++){
                int next=graph[cur][j].first;
                int cost=graph[cur][j].second-earn[next];
                if(table[cur]==INF) continue;
                if(table[cur]+cost<table[next]){
                    table[next]=table[cur]+cost;
                }
            }
        }
    }
    set<int> negative;
    bool isNegative=false;
    for(int cur=0;cur<n;cur++){
        for(int j=0;j<graph[cur].size();j++){
            int next=graph[cur][j].first;
            int cost=graph[cur][j].second-earn[next];
            if(table[cur]==INF) continue;
            if(table[cur]+cost<table[next]){
                negative.insert(next);
                isNegative=true;
            }
        }
    }
    set<int>::iterator iter=negative.begin();
    for(iter;iter!=negative.end();iter++){
        memset(visited,0,sizeof(visited));
        if(canGo(*iter, e)) return true;
    }
    fill(table,table+101,INF);
    table[v]=-earn[v];
    for(int i=0;i<n-1;i++){
        for(int cur=0;cur<n;cur++){
            for(int j=0;j<graph[cur].size();j++){
                int next=graph[cur][j].first;
                int cost=graph[cur][j].second-earn[next];
                if(table[cur]==INF||negative.count(next)!=0) continue;
                if(table[cur]+cost<table[next]){
                    table[next]=table[cur]+cost;
                }
            }
        }
    }
    return false;
}
int main(){
    scanf("%d %d %d %d",&n,&s,&e,&m);
    fill(table,table+101,INF);
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        graph[a].push_back({b,c});
    }
    for(int i=0;i<n;i++) scanf("%d",&earn[i]);
    bool negativeCycle=bellmanford(s);
    if(table[e]==INF) printf("gg");
    else if(negativeCycle) printf("Gee");
    else printf("%lld",-table[e]);
}