#include <bits/stdc++.h>
using namespace std;
int m[25][25];
bool visited[25][25];
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};
int n, cnt;
bool inside(int y, int x){
    if(y>=0&&x>=0&&y<n&&x<n) return true;
    return false;
}
int bfs(int y, int x){
    queue<pair<int,int>> q;
    q.push({y,x});
    visited[y][x]=true;
    int cnt=1;
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(inside(ny,nx)&&!visited[ny][nx]&&m[ny][nx]==1){
                q.push({ny,nx});
                cnt++;
                visited[ny][nx]=true;
            }
        }
    }
    return cnt;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) scanf("%1d",&m[i][j]);
    }
    vector<int> ans;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j]&&m[i][j]==1){
                ans.push_back(bfs(i,j));
                cnt++;
            }
        }
    }
    printf("%d\n",cnt);
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++) printf("%d\n",ans[i]);
}