#include <iostream>
using namespace std;
int n,m;
char pan[50][50];
bool visited[50][50];
int dist[50][50];
int dy[4]={0,0,-1,1};
int dx[4]={1,-1,0,0};
bool inside(int ny, int nx){
    if(ny>=0&&nx>=0&&ny<n&&nx<m) return true;
    return false;
}
bool go(int y, int x, int cnt, char color){
    if(visited[y][x]){
        if(cnt-dist[y][x]>=4) return true;
        else return false;
    }
    visited[y][x]=true; dist[y][x]=cnt;
    for(int i=0;i<4;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(!inside(ny,nx)) continue;
        if(pan[ny][nx]!=color) continue;
        if(go(ny,nx,cnt+1,color)) return true;
    }
    return false;
}
int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int j=0;j<m;j++) pan[i][j]=s[j];
    }
    bool flag=false;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited[i][j]) continue;
            flag=go(i,j,0,pan[i][j]);
            if(flag) break;
        }
        if(flag) break;
    }
    if(flag) cout << "Yes";
    else cout << "No";
}