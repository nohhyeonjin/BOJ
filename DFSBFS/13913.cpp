#include <iostream>
#include <queue>
#define MAX 200000
using namespace std;
int n,k;
int visited[MAX+1];
int from[MAX+1];
//가장 빠른 시간
//가중치는 시간
void bfs(){
    queue<int> q;
    q.push(n);
    visited[n]=0;
    while(!q.empty()){
        int cur=q.front();
        if(cur==k) return;
        q.pop();
        if(cur+1<=MAX&&visited[cur+1]==-1){
            q.push(cur+1);
            from[cur+1]=cur;
            visited[cur+1]=visited[cur]+1;
        }
        if(cur-1>=0&&visited[cur-1]==-1){
            q.push(cur-1);
            from[cur-1]=cur;
            visited[cur-1]=visited[cur]+1;
        }
        if(2*cur<=MAX&&visited[2*cur]==-1){
            q.push(2*cur);
            from[2*cur]=cur;
            visited[2*cur]=visited[cur]+1;
        }
    }
}
void print(int x){
    if(x==-1) return;
    print(from[x]);
    cout << x << " "; 
}
int main(){
    fill(visited,visited+MAX,-1);
    fill(from,from+MAX,-1);
    cin >> n >> k;
    bfs();
    cout << visited[k] << "\n";
    print(k);
}