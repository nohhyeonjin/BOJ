#include <bits/stdc++.h>
using namespace std;
int h,w;
int area[100][100]; //0-치즈없는칸 1-치즈있는칸 2-공기와 맞닿은 치즈
int visited[100][100];
int sec;
stack<int> cheezeSizes;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int cal_cheezeSize(){
    int cnt=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(area[i][j]==1) cnt++;
        }
    }
    return cnt;
}
bool inside(int ny, int nx){
    if(ny>=0&&nx>=0&&ny<h&&nx<w) return true;
    return false;
}
void dfs(int y, int x){
    for(int i=0;i<100;i++) memset(visited[i],0,sizeof(int)*100);
    queue<pair<int,int>> q;
    q.push({y,x});
    visited[y][x]=1;
    while(!q.empty()){
        pair<int,int> cur=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int ny=cur.first+dy[i];
            int nx=cur.second+dx[i];
            if(inside(ny,nx)&&area[ny][nx]==1) area[ny][nx]=2;
        }
        for(int i=0;i<4;i++){
            int ny=cur.first+dy[i];
            int nx=cur.second+dx[i];
            if(inside(ny,nx)&&area[ny][nx]==0&&visited[ny][nx]==0){
                q.push({ny,nx});
                visited[ny][nx]=1;
            }
        }
    }
}
void melt_cheeze(){
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(area[i][j]==2) area[i][j]=0;
        }
    }
}
void solution(){
    while(1){
        //get cheeze size
        int cheezeSize=cal_cheezeSize();
        if(cheezeSize==0) return;
        cheezeSizes.push(cheezeSize);

        //치즈 테두리 구하기
        dfs(0,0);
        
        //치즈 녹이기
        sec++;
        melt_cheeze();
    }
}
int main(){
    scanf("%d %d",&h,&w);
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++) scanf("%d",&area[i][j]);
    }
    solution();
    printf("%d\n%d",sec,cheezeSizes.top());
}