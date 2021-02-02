#include <bits/stdc++.h>
#define MAX 100001
using namespace std;
int n,k;
int ans;
bool visited[MAX];
void bfs(){
    queue<pair<int,int>> q;
    q.push({n,0});
    visited[n]=true;
    while(!q.empty()){
        int pos=q.front().first;
        int time=q.front().second;
        q.pop();
        if(pos==k){
            ans=time;
            break;
        }
        if(pos+1<MAX&&!visited[pos+1]){
            visited[pos+1]=true;
            q.push({pos+1,time+1});
        }
        if(pos-1>=0&&!visited[pos-1]){
            visited[pos-1]=true;
            q.push({pos-1,time+1});
        }
        if(pos*2<MAX&&!visited[pos*2]){
            visited[pos*2]=true;
            q.push({pos*2,time+1});
        }
    }
}
int main(){
    scanf("%d %d",&n,&k);
    bfs();
    printf("%d",ans);
}