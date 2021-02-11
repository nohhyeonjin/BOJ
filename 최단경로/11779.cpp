#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
int n,m,s,e;
vector<pair<int,int>> graph[1001];
int table[1001];
int from[1001];
void dijkstra(int start){
    priority_queue<pair<int,int>> pq;
    pq.push({0,start});
    table[start]=0;
    while(!pq.empty()){
        int cur=pq.top().second;
        int dist=-pq.top().first;
        pq.pop();
        if(table[cur]<dist) continue;
        for(int i=0;i<graph[cur].size();i++){
            int cost=dist+graph[cur][i].second;
            int next=graph[cur][i].first;
            if(table[next]>cost){
                pq.push({-cost,next});
                from[next]=cur;
                table[next]=cost;
            }
        }
    }
}
vector<int> route;
void getRoute(int v){
    route.push_back(v);
    if(v==s) return;
    getRoute(from[v]);
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        graph[a].push_back({b,c});
    }
    scanf("%d %d",&s,&e);
    fill(table,table+1001,INF);
    dijkstra(s);
    getRoute(e);
    printf("%d\n",table[e]);
    printf("%d\n",route.size());
    for(int i=route.size()-1;i>=0;i--) printf("%d ",route[i]);
}