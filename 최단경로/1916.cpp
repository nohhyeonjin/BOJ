#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
int n,m;
vector<pair<int,int>> graph[1001];  //vertex:vertex,cost
int table[1001];
void dijkstra(int start){
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,start));    //cost, vertex;
    table[start]=0;
    while(!pq.empty()){
        int dist=-pq.top().first;
        int now=pq.top().second;
        pq.pop();
        if(dist>table[now]) continue;
        for(int i=0;i<graph[now].size();i++){
            int cost=dist+graph[now][i].second;
            int vNum=graph[now][i].first;
            if(cost<table[vNum]){
                table[vNum]=cost;
                pq.push(make_pair(-cost,vNum));
            }
        }
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        graph[a].push_back(make_pair(b,c));
    }
    fill(table,table+1001,INF);
    int start,end;
    scanf("%d %d",&start,&end);
    dijkstra(start);
    printf("%d",table[end]);
}