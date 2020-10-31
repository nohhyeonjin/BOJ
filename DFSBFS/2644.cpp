#include <bits/stdc++.h>
#define MAX 101
using namespace std;
vector<int> tree[MAX];
int visited[MAX];
int ans;
void dfs(int v, int target, int sum){
    if(v==target){
        ans=sum;
        return;
    }
    visited[v]=1;
    for(int i=0;i<tree[v].size();i++){
        int next=tree[v][i];
        if(!visited[next]) dfs(next,target,sum+1);
    }
}
int main(){
    int n,a,b,m;
    scanf("%d %d %d %d",&n,&a,&b,&m);
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    dfs(a,b,0);
    if(ans==0) printf("-1");
    else printf("%d",ans);
}