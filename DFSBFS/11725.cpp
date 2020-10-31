#include <bits/stdc++.h>
#define MAX 100001
using namespace std;
vector<int> tree[MAX];
int parent[MAX];
void dfs(int v){
    queue<int> q;
    q.push(v);
    parent[v]=1;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int i=0;i<tree[cur].size();i++){
            int next=tree[cur][i];
            if(parent[next]==0){
                parent[next]=cur;
                q.push(next);
            }
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int a, b;
        scanf("%d %d",&a,&b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1);
    for(int i=2;i<=n;i++) printf("%d\n",parent[i]);
}