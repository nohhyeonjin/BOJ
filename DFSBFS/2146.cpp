#include <bits/stdc++.h>
using namespace std;
int n;
int landNum;
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};
int m[100][100];
int visited[100][100];
bool inside(int ny, int nx){
    if(ny>=0&&nx>=0&&ny<n&&nx<n) return true;
    return false;
}
void numbering(int y, int x){
    queue<pair<int,int>> q;
    q.push({y,x});
    landNum++;
    visited[y][x]=1;
    m[y][x]=landNum;
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(!inside(ny,nx)) continue;
            if(visited[ny][nx]==0&&m[ny][nx]==1){
                q.push({ny,nx});
                m[ny][nx]=landNum;
                visited[ny][nx]=1;
            }
        }
    }
}
int buildBridge(int num){
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(m[i][j]==num){
                q.push({i,j});
                visited[i][j]=1;
            }
        }
    }
    int len=0;
    while(!q.empty()){
        int s=q.size();
        for(int i=0;i<s;i++){
            int y=q.front().first;
            int x=q.front().second;
            q.pop();
            for(int j=0;j<4;j++){
                int ny=y+dy[j];
                int nx=x+dx[j];
                if(!inside(ny,nx)||visited[ny][nx]==1) continue;
                if(m[ny][nx]!=0&&m[ny][nx]!=num) return len;
                if(m[ny][nx]==0){
                    q.push({ny,nx});
                    visited[ny][nx]=1;
                }
            }
        }
        len++;
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) scanf("%d",&m[i][j]);
    }
    //섬번호 부여하기
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(m[i][j]==1&&visited[i][j]==0) numbering(i,j);
        }
    }
    int ans=1e9;
    //다리놓기
    for(int i=1;i<=landNum;i++){
        for(int i=0;i<n;i++) memset(visited[i],0,sizeof(visited[i]));
        ans=min(ans,buildBridge(i));
    }
    printf("%d",ans);
}