#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
int a[1001][1001];
int visited[1001];
void dfs(int vNum, int v){
    printf("%d ",v);
    visited[v]=1;
    for(int i=1;i<=vNum;i++){
        if(a[v][i]==1 && visited[i]!=1) dfs(vNum,i);
    }
}
void bfs(int vNum, int v){
    queue<int> q;
    visited[v]=1;
    q.push(v);
    while(!q.empty()){
        int current=q.front();
        printf("%d ",current);
        q.pop();
        for(int i=1;i<=vNum;i++){
            if(a[current][i]==1 && visited[i]!=1) {
                visited[i]=1;
                q.push(i);
            }
        }
    }
}
int main(){
    int v, e, s;
    scanf("%d %d %d",&v, &e, &s);
    //인접행렬초기화
    for(int i=0;i<e;i++){
        int v1,v2;
        scanf("%d %d",&v1,&v2);
        a[v1][v2]=1;
        a[v2][v1]=1;
    }
    dfs(v,s);
    printf("\n");
    memset(visited,0,sizeof(visited));
    bfs(v,s);
}