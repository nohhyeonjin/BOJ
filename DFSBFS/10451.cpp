#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
int visited[1001];
int graph[1001];
void dfs(int v){
    visited[v]=1;
    if(visited[graph[v]]==0) dfs(graph[v]);
}
int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int vNum;
        scanf("%d",&vNum);
        memset(visited,0,sizeof(visited));
        memset(graph,0,sizeof(graph));
        for(int j=1;j<=vNum;j++) scanf("%d",&graph[j]);
        int answer=0;
        for(int j=1;j<=vNum;j++) {
            if(visited[j]==0) {
                dfs(j);
                answer++;
            }
        }
        printf("%d\n",answer);
    }
}