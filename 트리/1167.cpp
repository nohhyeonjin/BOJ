#include <bits/stdc++.h>
using namespace std;
int v;
vector<pair<int,int>> graph[100001];
int visited[100001];
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
    scanf("%d",&v);
    for(int i=0;i<v;i++){
        int vNum;
        scanf("%d",&vNum);
        while(1){
            int a,b;
            scanf("%d",&a);
            if(a==-1) break;
            scanf("%d",&b);
            graph[vNum].push_back({a,b});
        }
    }
    dfs(1,0);
    memset(visited,0,sizeof(visited));
    dfs(maxV,0);
    printf("%d",ans);
}