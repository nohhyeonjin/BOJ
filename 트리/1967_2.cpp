#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int>> graph[10001]; //부모->{자식,가중치}
int visited[10001];
int ans;
int maxV;
void dfs(int v, int sum){
    visited[v]=1;
    if(sum>ans){
        ans=sum;
        maxV=v;
    }
    for(int i=0;i<graph[v].size();i++){
        int next=graph[v][i].first;
        int cost=graph[v][i].second;
        if(visited[next]==0) dfs(next,sum+cost);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    dfs(1,0);
    memset(visited,0,sizeof(visited));
    dfs(maxV,0);
    printf("%d",ans);
}