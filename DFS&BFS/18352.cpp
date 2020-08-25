#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph(300001);
int visited[300001];
void bfs(int start){
    queue<int> q;
    visited[start]=1;
    q.push(start);
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        int len=graph[cur].size();
        for(int i=0;i<len;i++){
            int v=graph[cur][i];
            if(visited[v]==0){
                q.push(v);
                visited[v]=visited[cur]+1;
            }
        }
    }
}
int main(){
   int n,m,k,x;
   scanf("%d %d %d %d",&n,&m,&k,&x);
    for(int i=0;i<m;i++){
        int v1,v2;
        scanf("%d %d",&v1,&v2);
        graph[v1].push_back(v2);
    }
    bfs(x);
    vector<int> ans;
    for(int i=0;i<300001;i++){
        if(visited[i]-1==k) ans.push_back(i);
    }
    if(ans.size()==0) printf("-1");
    for(int i=0;i<ans.size();i++) printf("%d\n",ans[i]);
}