#include <bits/stdc++.h>
using namespace std;
int m,n;
int ans;
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};
int box[1000][1000];
int visited[1000][1000];
queue<pair<int,int>> q;
bool inside(int y, int x){
    if(y>=0&&x>=0&&y<n&&x<m) return true;
    return false;
}
void bfs(){
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        int day=box[y][x];
        ans=max(ans,day);
        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(inside(ny,nx)&&visited[ny][nx]==0&&box[ny][nx]==0){
                visited[ny][nx]=1;
                q.push({ny,nx});
                box[ny][nx]=day+1;
            }
        }
    }
}
int main(){
    scanf("%d %d",&m,&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&box[i][j]);
            if(box[i][j]==1) q.push({i,j});
        }
    }
    visited[q.front().first][q.front().second]=1;
    bfs();
    bool flag=true;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(box[i][j]==0) flag=false;
        }
    }
    printf("%d",flag?ans-1:-1);
}