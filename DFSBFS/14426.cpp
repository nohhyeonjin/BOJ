#include <iostream>
#include <queue>
#include <map>
using namespace std;
int s;
int ans;
map<pair<int,int>,int> visited;
void bfs(){
    queue<pair<int,int>> q;
    q.push({1,0});
    visited.insert({{1,0},0});
    while(!q.empty()){
        int curI=q.front().first;
        int curC=q.front().second;
        if(curI==s){
            ans=visited[{curI,curC}];
            return;
        }
        q.pop();
        
        //1
        int nextI=curI;
        int nextC=curI;
        if(visited.count({nextI,nextC})==0){
            visited.insert({{nextI,nextC},visited[{curI,curC}]+1});
            q.push({nextI,nextC});
        }

        //2
        nextI=curI+curC;
        nextC=curC;
        if(visited.count({nextI,nextC})==0){
            visited.insert({{nextI,nextC},visited[{curI,curC}]+1});
            q.push({nextI,nextC});
        }

        //3
        nextI=curI-1;
        nextC=curC;
        if(visited.count({nextI,nextC})==0){
            visited.insert({{nextI,nextC},visited[{curI,curC}]+1});
            q.push({nextI,nextC});
        }
    }
}
int main(){
    cin >> s;
    bfs();
    cout << ans;
}