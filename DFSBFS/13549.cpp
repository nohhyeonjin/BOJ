#include <iostream>
#include <queue>
#define MAX 200000
using namespace std;
int n,k;
int visited[MAX+1];
void bfs(){
    deque<int> q;
    q.push_back(n);
    visited[n]=0;
    while(!q.empty()){
        int cur=q.front();
        if(cur==k) return;
        q.pop_front();
        if(2*cur<=MAX&&visited[2*cur]==-1){
            visited[2*cur]=visited[cur];
            q.push_front(2*cur);
        }
        if(cur-1>=0&&visited[cur-1]==-1){
            visited[cur-1]=visited[cur]+1;
            q.push_back(cur-1);
        }
        if(cur+1<=MAX&&visited[cur+1]==-1){
            visited[cur+1]=visited[cur]+1;
            q.push_back(cur+1);
        }
        
    }
}
int main(){
    fill(visited,visited+MAX,-1);
    cin >> n >> k;
    bfs();
    cout << visited[k];
}