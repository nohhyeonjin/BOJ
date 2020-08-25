#include <stdio.h>
int a[1001][1001];
int visited[1001];
void dfs(int vNum, int v){
    visited[v]=1;
    for(int i=1;i<=vNum;i++){
        if(a[v][i]==1 && visited[i]!=1) dfs(vNum, i);
    }
}
int main(){
    int v, e;
    int cnt=0;
    scanf("%d %d",&v,&e);
    for(int i=0;i<e;i++){
        int v1, v2;
        scanf("%d %d",&v1, &v2);
        a[v1][v2]=1;
        a[v2][v1]=1;
    }
    for(int i=1;i<=v;i++){
        if(visited[i]!=1) {
            dfs(v,i);
            cnt++;
        }
    }
    printf("%d",cnt);
}