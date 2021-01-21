#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> graph[100001];
int visited[100001];
int parent[100001];
void dfs(int v){
    visited[v]=1;
    for(int i=0;i<graph[v].size();i++){
        int next=graph[v][i];
        if(visited[next]==0){
            parent[next]=v;
            dfs(next);
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1);
    for(int i=2;i<=n;i++) printf("%d\n",parent[i]);
}