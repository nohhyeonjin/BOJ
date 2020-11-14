#include <bits/stdc++.h>
#define MAX 1001
#define INF 1e9
using namespace std;
int n,m,x;
int ans;
vector<pair<int,int>> edges[MAX];   //a->{b,c}
int table[MAX];
int arr[MAX];
void dijkstra(int start){
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
}
int main(){
    scanf("%d %d %d",&n,&m,&x);
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        edges[a].push_back({b,c});
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) table[j]=INF;
        dijkstra(i);
        arr[i]=table[x];
    }
    for(int i=1;i<=n;i++) table[i]=INF;
    dijkstra(x);
    for(int i=1;i<=n;i++) arr[i]+=table[i];
    for(int i=1;i<=n;i++) ans=max(ans,arr[i]);
    printf("%d",ans);
}