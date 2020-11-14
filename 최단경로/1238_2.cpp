#include <bits/stdc++.h>
#define MAX 1001
#define INF 1e9
using namespace std;
int n,m,x;
int ans;
vector<vector<pair<int,int>>> edges, revEdges;   //a->{b,c}
int table[MAX];
int arr[MAX];
void dijkstra(vector<vector<pair<int,int>>> edges, int start){
    for(int i=1;i<=n;i++) table[i]=INF;
    priority_queue<pair<int,int>> pq;   //cost, vNum
    pq.push({0,start});
    table[start]=0;
    while(!pq.empty()){
        int now=pq.top().second;
        int dist=-pq.top().first;
        pq.pop();
        if(dist>table[now]) continue;
        for(int i=0;i<edges[now].size();i++){
            int vNum=edges[now][i].first;
            int cost=dist+edges[now][i].second;
            if(cost<table[vNum]){
                pq.push({-cost,vNum});
                table[vNum]=cost;
            }
        }
    }
    for(int i=1;i<=n;i++) arr[i]+=table[i];
}
int main(){
    scanf("%d %d %d",&n,&m,&x);
    edges.resize(n+1);
    revEdges.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        edges[a].push_back({b,c});
        revEdges[b].push_back({a,c});
    }
    dijkstra(revEdges,x);
    dijkstra(edges,x);
    for(int i=1;i<=n;i++) ans=max(ans,arr[i]);
    printf("%d",ans);
}