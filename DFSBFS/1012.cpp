#include <bits/stdc++.h>
using namespace std;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int m,n,k;
int arr[50][50];
int visited[50][50];
bool inside(int ny, int nx){
    if(ny>=0&&nx>=0&&ny<n&&nx<m) return true;
    return false;
}
void bfs(int y, int x){
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
            if(inside(ny,nx)&&visited[ny][nx]==0&&arr[ny][nx]==1){
                q.push({ny,nx});
                visited[ny][nx]=1;
            }
        }
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&m,&n,&k);
        for(int i=0;i<50;i++) memset(arr[i],0,sizeof(int)*50);
        for(int i=0;i<50;i++) memset(visited[i],0,sizeof(int)*50);
        for(int i=0;i<k;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            arr[y][x]=1;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==1&&visited[i][j]==0){
                    ans++;
                    bfs(i,j);
                }
            }
        }
        printf("%d\n",ans);
    }
}