#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
int graph[100][100];
int visited[100][100];
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
bool inside(int y,int x){
    if(y>=0&&x>=0&&y<n&&x<n) return true;
    return false;
}
void dfs(int y,int x, int h){
    queue<pair<int,int>> q;
    q.push(make_pair(y,x));
    visited[y][x]=1;
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(inside(ny,nx)&&graph[ny][nx]>h&&visited[ny][nx]==0){
                q.push(make_pair(ny,nx));
                visited[ny][nx]=1;
            }
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int num;
            scanf("%d",&num);
            graph[i][j]=num;
            m=max(m,num);
        }
    }
    for(int i=0;i<=m;i++){
        for(int j=0;j<n;j++) memset(visited[j],0,sizeof(int)*n);
        int cnt=0;
        for(int h=0;h<n;h++){
            for(int w=0;w<n;w++){
                if(graph[h][w]>i&&visited[h][w]==0){
                    dfs(h,w,i);
                    cnt++;
                }
            }
        }
        ans=max(ans,cnt);
    }
    printf("%d",ans);
}