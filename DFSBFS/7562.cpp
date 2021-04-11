#include <iostream>
#include <queue>
using namespace std;
int t;
int pan[300][300];
int visited[300][300];
int s,fx,fy,tx,ty;
int dy[8]={-2,-1,1,2,2,1,-1,-2};
int dx[8]={1,2,2,1,-1,-2,-2,-1};
bool inside(int ny, int nx){
    if(ny>=0&&nx>=0&&ny<s&&nx<s) return true;
    return false;
}
int bfs(){
    for(int i=0;i<s;i++) fill(visited[i],visited[i]+300,-1);
    queue<pair<int,int>> q;
    q.push({fy,fx});
    visited[fy][fx]=0;
    while(!q.empty()){
        int curX=q.front().second;
        int curY=q.front().first;
        if(curY==ty&&curX==tx) return visited[curY][curX];
        q.pop();
        for(int i=0;i<8;i++){
            int ny=curY+dy[i];
            int nx=curX+dx[i];
            if(inside(ny,nx)&&visited[ny][nx]==-1){
                q.push({ny,nx});
                visited[ny][nx]=visited[curY][curX]+1;
            }
        }
    }
}
int main(){
    cin >> t;
    while(t--){
        cin >> s >> fx >> fy >> tx >> ty;
        cout << bfs() << "\n";
    }
}