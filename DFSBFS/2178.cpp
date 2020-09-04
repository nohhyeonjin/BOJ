#include <bits/stdc++.h>
using namespace std;
int n,m;
int maze[100][100];
int visited[100][100];
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};
bool inside(int ny,int nx){
    if(ny>=0&&nx>=0&&ny<n&&nx<m) return true;
    return false;
}
void bfs(){
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    visited[0][0]=1;
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        int cnt=maze[y][x]+1;
        q.pop();
        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(inside(ny,nx)&&maze[ny][nx]>0&&visited[ny][nx]==0){
                q.push(make_pair(ny,nx));
                maze[ny][nx]=cnt;
                visited[ny][nx]=1;
            }
        }
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) scanf("%1d",&maze[i][j]);
    }
    bfs();
    printf("%d",maze[n-1][m-1]);
}