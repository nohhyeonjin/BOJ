#include <bits/stdc++.h>
using namespace std;
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};
set<string> visited;
vector<vector<int>> puzzle;
bool inside(int ny, int nx){
    if(ny>=0&&nx>=0&&ny<3&&nx<3) return true;
    return false;
}
string puzzleToString(vector<vector<int>> v){
    string tmp="";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++) tmp+=to_string(v[i][j]);
    }
    return tmp;
}
bool isAnswer(vector<vector<int>> v){
    string tmp="";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++) tmp+=to_string(v[i][j]);
    }
    if(tmp=="123456780") return true;
    return false;
}
int bfs(vector<vector<int>> p){
    queue<pair<vector<vector<int>>,int>> q;
    q.push({p,0});
    while(!q.empty()){
        vector<vector<int>> v=q.front().first;
        int cnt=q.front().second;
        q.pop();
        if(isAnswer(v)) return cnt;
        //0위치 찾기
        int y,x;
        bool flag=false;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(v[i][j]==0){
                    y=i; x=j;
                    flag=true;
                    break;
                }
            }
            if(flag) break;
        }
        //4방향탐색
        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(!inside(ny,nx)) continue;
            v[y][x]=v[ny][nx];
            v[ny][nx]=0;
            string str=puzzleToString(v);
            if(visited.count(str)==0){
                visited.insert(str);
                q.push({v,cnt+1});
            }
            v[ny][nx]=v[y][x];
            v[y][x]=0;
        }
    }
    return -1;
}
int main(){
    puzzle.resize(3);
    for(int i=0;i<3;i++) puzzle[i].resize(3);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++) scanf("%d",&puzzle[i][j]);
    }
    printf("%d",bfs(puzzle));
}