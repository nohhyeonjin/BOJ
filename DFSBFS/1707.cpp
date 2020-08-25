#include <stdio.h>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;

int visited[20001];

bool bfs(vector<int>* graph, int v){
    queue<int> q;
    q.push(v);
    visited[v]=1;
    while(!q.empty()){
        int current=q.front();
        q.pop();
        int parentColor = visited[current];
        for(int i=0;i<graph[current].size();i++){
            int c=graph[current][i];
            if(visited[c]==0){
                if(parentColor==1) visited[c]=2;
                else visited[c]=1;
                q.push(c);
            }else{
                if(parentColor==visited[c]) return false;
            }
        }
    }
    return true;
}
int main(){
    int t, v, e;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d %d",&v,&e);
        vector<int> graph[20001];
        memset(visited,0,sizeof(visited));
        for(int i=0;i<e;i++){
            int v1,v2;
            scanf("%d %d",&v1,&v2);
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }
        bool answer=true;
        for(int i=1;i<=v;i++){
            if(visited[i]==0&&answer==true) answer=bfs(graph, i);
        }
        printf(answer?"YES\n":"NO\n");
    }
}