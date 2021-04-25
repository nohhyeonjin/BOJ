#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int n,m;
int pan[1000][1000];
bool visited[1000][1000][2];
int dy[4]={0,0,1,-1};
int dx[4]={1,-1,0,0};
bool inside(int ny, int nx){
    if(ny>=0&&nx>=0&&ny<n&&nx<m) return true;
    return false;
} 
int bfs(int y, int x){
    queue<tuple<int,int,int,int>> q;    //y,x,벽부순횟수,거리
    q.push(make_tuple(y,x,0,1));
    visited[y][x][0]=true;
    while(!q.empty()){
        int y,x,z,dist;
        tie(y,x,z,dist)=q.front();
        q.pop();
        if(y==n-1&&x==m-1) return dist;
        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(!inside(ny,nx)) continue;
            if(z==1&&pan[ny][nx]==1) continue;
            if((z==0&&pan[ny][nx]==1)||(z==1&&pan[ny][nx]==0)){
                if(visited[ny][nx][1]) continue;
                visited[ny][nx][1]=true;
                q.push(make_tuple(ny,nx,1,dist+1));
            }else{
                if(visited[ny][nx][0]) continue;
                visited[ny][nx][0]=true;
                q.push(make_tuple(ny,nx,0,dist+1));
            }
        }
    }
    return -1;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) scanf("%1d",&pan[i][j]);
    }
    printf("%d",bfs(0,0));
}