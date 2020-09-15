#include <bits/stdc++.h>
using namespace std;
int n, cnt;
char graph[100][100];
int visited[100][100];
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
bool inside(int ny, int nx){
    if(ny>=0&&nx>=0&&ny<n&&nx<n) return true;
    return false;
}
void bfs(int y, int x, int code){
    queue<pair<int,int>> q;
    q.push({y,x});
    visited[y][x]=1;
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(inside(ny,nx)==false||visited[ny][nx]==1) continue;
            if((code==0&&(graph[ny][nx]=='R'||graph[ny][nx]=='G'))||(code==1&&graph[ny][nx]=='B')){
                q.push({ny,nx});
                visited[ny][nx]=1;
            }
        }
    }
}
void bfsN(int y, int x, char color){
    queue<pair<int,int>> q;
    q.push({y,x});
    visited[y][x]=1;
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(inside(ny,nx)==false||visited[ny][nx]==1) continue;
            if(graph[ny][nx]==color){
                q.push({ny,nx});
                visited[ny][nx]=1;
            }
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char c;
            cin >> c;
            graph[i][j]=c;
        }
    }
    //적록색약 아닌사람
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j]==0){    
                char color=graph[i][j];
                bfsN(i,j,color);
                cnt++;
            }
        }
    }
    printf("%d ",cnt);
    cnt=0;
    for(int i=0;i<n;i++) memset(visited[i],0,sizeof(int)*n);
    //적록색약
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if((graph[i][j]=='R'||graph[i][j]=='G')&&visited[i][j]==0){
                bfs(i,j,0);
                cnt++;
            }
            if(graph[i][j]=='B'&&visited[i][j]==0){
                bfs(i,j,1);
                cnt++;
            }
        }
    }
    printf("%d",cnt);
}