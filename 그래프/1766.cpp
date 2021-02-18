#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> edges[32001];
int inDegree[32001];
vector<int> result;
void topologySort(){
    priority_queue<int> pq;
    for(int i=1;i<=n;i++) if(inDegree[i]==0) pq.push(-i);
    while(!pq.empty()){
        int cur=-pq.top();
        result.push_back(cur);
        pq.pop();
        for(int i=0;i<edges[cur].size();i++){
            int next=edges[cur][i];
            inDegree[next]--;
            if(inDegree[next]==0) pq.push(-next);
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
    for(int i=0;i<n;i++) printf("%d ",result[i]);
}