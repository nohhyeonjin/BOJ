#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int>> graph[10001]; //부모->{자식,가중치}
int visited[10001];
int ans;
void dfs(int v, int sum){
    visited[v]=1;
    for(int i=0;i<graph[v].size();i++){
        if((graph[v].size()==1)&&(visited[graph[v][0].first]==1)){
            ans=max(ans,sum);
            break;
        }
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
    for(int i=1;i<=n;i++){
        memset(visited,0,sizeof(visited));
        dfs(i,0);
    }
    printf("%d",ans);
}