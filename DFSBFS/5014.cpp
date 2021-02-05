#include <bits/stdc++.h>
using namespace std;
int f,s,g,u,d;
bool visited[1000001];
int bfs(){
    queue<pair<int,int>> q;
    q.push({s,0});
    visited[s]=true;
    while(!q.empty()){
        int cur=q.front().first;
        int button=q.front().second;
        if(cur==g) return button;
        q.pop();
        if(cur+u<=f&&!visited[cur+u]){
            q.push({cur+u,button+1});
            visited[cur+u]=true;
        }
        if(cur-d>=1&&!visited[cur-d]){
            q.push({cur-d,button+1});
            visited[cur-d]=true;
        }
    }
    return -1;
}
int main(){
    scanf("%d %d %d %d %d",&f,&s,&g,&u,&d);
    int ans=bfs();
    if(ans==-1) printf("use the stairs");
    else printf("%d",ans);
}