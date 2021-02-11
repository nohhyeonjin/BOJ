#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
int n,m;
vector<pair<int,int>> graph[1001];  //a->{b,c}
int table[1001];
int from[1001];
set<pair<int,int>> route;
void dijkstra(int start){
    priority_queue<pair<int,int>> pq;   //{cost, num}
    pq.push({0,start});
    table[start]=0;
    while(!pq.empty()){
        int cur=pq.top().second;
        int cost=-pq.top().first;
        pq.pop();
        if(table[cur]<cost) continue;
        for(int i=0;i<graph[cur].size();i++){
            int next=graph[cur][i].first;
            int dist=cost+graph[cur][i].second;
            if(dist<table[next]){
                pq.push({-dist,next});
                table[next]=dist;
                from[next]=cur;
            }
        }
    }
}
void getRoute(int vertex){
    if(vertex==1) return;
    int a=vertex;
    int b=from[vertex];
    if(b<a){
        a=from[vertex];
        b=vertex;
    }
    route.insert({a,b});
    getRoute(from[vertex]);
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    fill(table,table+1001,INF);
    dijkstra(1);
    for(int i=1;i<=n;i++) getRoute(i);
    printf("%d\n",route.size());
    set<pair<int,int>>::iterator iter = route.begin();
    for(iter;iter!=route.end();iter++){
        printf("%d %d\n",iter->first, iter->second);
    }
}