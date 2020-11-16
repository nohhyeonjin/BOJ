#include <bits/stdc++.h>
#define MAX 50
using namespace std;
int n,m;
int room[MAX][MAX];
int roomCnt, maxArea;
int visited[MAX][MAX];
int dy[4]={0,-1,0,1};   //서,북,동,남
int dx[4]={-1,0,1,0};
bool inside(int ny,int nx){
    if(ny>=0&&nx>=0&&ny<m&&nx<n) return true;
    return false;
}
int bfs(int y, int x){
    queue<pair<int,int>> q;
    q.push({y,x});
    visited[y][x]=1;
    int area=1;
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            if(room[y][x]&(1<<i)) continue;
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(!visited[ny][nx]&&inside(ny,nx)){
                q.push({ny,nx});
                area++;
                visited[ny][nx]=1;
            }
        }
    }
    return area;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++) scanf("%d",&room[i][j]);
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j]){
                maxArea=max(maxArea,bfs(i,j));
                roomCnt++;
            }
        }
    }
    printf("%d\n",roomCnt);
    printf("%d\n",maxArea);
    maxArea=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<4;k++){
                if((room[i][j]&(1<<k))==0) continue;
                //벽허물기
                room[i][j]-=pow(2,k);
                //넓이구하기
                for(int l=0;l<MAX;l++) fill(visited[l],visited[l]+MAX,0);
                maxArea=max(maxArea,bfs(i,j));
                //벽다시쌓기
                room[i][j]+=pow(2,k);
            }
        }
    }
    printf("%d\n",maxArea);
}