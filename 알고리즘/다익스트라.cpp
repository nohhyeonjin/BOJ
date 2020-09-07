#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
int v,e,start;
vector<pair<int,int>> graph[101];   //vertex number, cost
int table[101];
void dijkstra(int start){
    priority_queue<pair<int,int>> pq;   //cost, vertex number
    pq.push(make_pair(0,start));
    table[start]=0;
    while(!pq.empty()){
        int dist=-pq.top().first;
        int now=pq.top().second;
        pq.pop();
        //이미 처리한 vertex라면 무시
        if(table[now]<dist) continue;
        //now와 연결된 다른 vertex들 확인
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
    //vertex개수, edge개수, 시작점
    cin >> v >> e >> start; 
    //edge 정보 입력받기
    for(int i=0;i<e;i++){
        int a,b,c;
        //a vertex에서 b vertex로 가는 비용 c
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b,c));
    }
    fill(table,table+101,INF);
    dijkstra(start);
    for(int i=1;i<=v;i++){
        if(table[i]==INF) cout << "INF" << "\n";
        else cout << table[i] << "\n";
    }
}