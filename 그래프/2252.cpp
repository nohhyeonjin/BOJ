#include <bits/stdc++.h>
using namespace std;
int n,m;
int inDegree[32001];
vector<int> edges[32001];
void topologySort(){
    queue<int> q;
    for(int i=1;i<=n;i++) if(inDegree[i]==0) q.push(i);
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        printf("%d ",cur);
        for(int i=0;i<edges[cur].size();i++){
            inDegree[edges[cur][i]]--;
            if(inDegree[edges[cur][i]]==0) q.push(edges[cur][i]);
        }
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        inDegree[b]++;
        edges[a].push_back(b);
    }
    topologySort();
}