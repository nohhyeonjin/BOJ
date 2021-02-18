#include <bits/stdc++.h>
using namespace std;
int n,m;
int s,e;
int inDegree[10001];
int dist[10001];
vector<pair<int,int>> edges[10001]; //a->{b,cost}
int from[10001];
vector<pair<int,int>> revEdges[10001];  //b->{a,cost}
void topologySort(){
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int i=0;i<edges[cur].size();i++){
            int next=edges[cur][i].first;
            int cost=edges[cur][i].second;
            if(dist[next]<dist[cur]+cost){
                dist[next]=dist[cur]+cost;
                from[next]=cur;
            }
            inDegree[next]--;
            if(inDegree[next]==0) q.push(next);
        }
    }
}
bool visited[10001];
int count(){
    int cnt=0;
    queue<int> q;
    q.push(e);
    visited[e]=true;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int i=0;i<revEdges[cur].size();i++){
            int next=revEdges[cur][i].first;
            int cost=revEdges[cur][i].second;
            if(dist[cur]-dist[next]==cost){
                cnt++;
                if(!visited[next]){
                    q.push(next);
                    visited[next]=true;
                }
            }
        }
    }
    return cnt;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        edges[a].push_back({b,c});
        revEdges[b].push_back({a,c});
        inDegree[b]++;
    }
    scanf("%d %d",&s,&e);
    topologySort();
    printf("%d\n",dist[e]);
    printf("%d",count());
}