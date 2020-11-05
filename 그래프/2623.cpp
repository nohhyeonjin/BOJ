#include <bits/stdc++.h>
using namespace std;
int n,m;
int inDegree[1001];
vector<int> edges[1001];
void topologySort(){
    queue<int> q;
    vector<int> result;
    for(int i=1;i<=n;i++) if(inDegree[i]==0) q.push(i);
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        result.push_back(cur);
        for(int i=0;i<edges[cur].size();i++){
            inDegree[edges[cur][i]]--;
            if(inDegree[edges[cur][i]]==0) q.push(edges[cur][i]);
        }
    }
    if(result.size()!=n) printf("0");
    else{
        for(int i=0;i<result.size();i++) printf("%d\n",result[i]);
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        int cnt;
        scanf("%d",&cnt);
        vector<int> v;
        for(int j=0;j<cnt;j++){
            int num;
            scanf("%d",&num);
            v.push_back(num);
        }
        for(int a=0;a<cnt;a++){
            for(int b=a+1;b<cnt;b++){
                inDegree[v[b]]++;
                edges[v[a]].push_back(v[b]);
            }
        }
    }
    topologySort();
}