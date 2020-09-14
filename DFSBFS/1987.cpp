#include <bits/stdc++.h>
using namespace std;
int r,c,ans;
char graph[20][20];
int visited[20][20];
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int alpha[26];
bool inside(int ny,int nx){
    if(ny>=0&&nx>=0&&ny<r&&nx<c) return true;
    return false;
}
void dfs(int y, int x, int dist){
    visited[y][x]=1;
    ans=max(ans,dist);
    alpha[graph[y][x]-'A']=1;
    for(int i=0;i<4;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(inside(ny,nx)&&visited[ny][nx]==0&&alpha[graph[ny][nx]-'A']==0) dfs(ny,nx,dist+1);
    }
    visited[y][x]=0;
    alpha[graph[y][x]-'A']=0;
}
int main(){
    scanf("%d %d",&r,&c);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++) cin >> graph[i][j];
    }
    dfs(0,0,1);
    printf("%d",ans);
}