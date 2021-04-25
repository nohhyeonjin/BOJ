#include <iostream>
#include <vector>
#include <queue>
#define MAX 3001
using namespace std;
int n;
vector<int> edges[MAX];
int chk[MAX];   //0-방문안함 1-방문함 2-사이클
int dist[MAX];
int go(int x, int p){
    if(chk[x]==1) return x;
    if(chk[x]==0) chk[x]=1; 
    for(int i=0;i<edges[x].size();i++){
        int next=edges[x][i];
        if(next==p) continue;
        int res=go(next,x);
        if(res==-2) return -2;
        if(res>0){
            chk[x]=2;
            if(res==x) return -2;
            else return res;
        }
    }
    return -1;
}
void bfs(){
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(chk[i]==2){
            q.push(i);
            dist[i]=0;
        }else dist[i]=-1;
    }
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int i=0;i<edges[cur].size();i++){
            int next=edges[cur][i];
            if(dist[next]!=-1) continue;
            dist[next]=dist[cur]+1;
            q.push(next);
        }
    } 
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    go(1,0);
    bfs();
    for(int i=1;i<=n;i++) printf("%d ",dist[i]);
}