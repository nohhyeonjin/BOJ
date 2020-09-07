#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
int v,e,start;
vector<pair<int,int>> graph[20001];
int table[20001];
void dijkstra(int start){
    priority_queue<pair<int,int>> pq;   //cost, vertex
    pq.push(make_pair(0,start));
    table[start]=0;
    while(!pq.empty()){
        int dist=-pq.top().first;
        int now=pq.top().second;
        pq.pop();
        if(dist>table[now]) continue;
        for(int i=0;i<graph[now].size();i++){
            int cost=dist+graph[now][i].second;
            int vNum=graph[now][i].first;
            if(table[vNum]>cost){
                table[vNum]=cost;
                pq.push(make_pair(-cost,vNum));
            }
        }
    }
}
int main(){
    scanf("%d %d %d",&v,&e,&start);
    fill(table,table+20001,INF);
    for(int i=0;i<e;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        graph[a].push_back(make_pair(b,c)); //vertex, cost
    }
    dijkstra(start);
    for(int i=1;i<=v;i++){
        if(table[i]==INF) printf("INF\n");
        else printf("%d\n",table[i]);
    }
}