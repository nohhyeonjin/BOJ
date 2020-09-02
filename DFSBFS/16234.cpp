#include <bits/stdc++.h>
using namespace std;
int n,l,r;
int land[50][50];
int visited[50][50];
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};
bool inside(int ny,int nx){
    if(ny>=0&&nx>=0&&ny<n&&nx<n) return true;
    return false;
}
bool open(int y,int x,int ny,int nx){
    if(abs(land[ny][nx]-land[y][x])>=l&&abs(land[ny][nx]-land[y][x])<=r) return true;
    return false;
}
bool start(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<4;k++){
                int ny=i+dy[k];
                int nx=j+dx[k];
                if(inside(ny,nx)&&open(i,j,ny,nx)) return true;
            }
        }
    }
    return false;
}
void bfs(int h,int w){
    queue<pair<int,int>> q;
    vector<pair<int,int>> v;
    int sum=land[h][w];
    int cnt=1;
    visited[h][w]=1;
    q.push(make_pair(h,w));
    v.push_back(make_pair(h,w));
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(inside(ny,nx)&&open(y,x,ny,nx)&&visited[ny][nx]==0){
                visited[ny][nx]=1;
                q.push(make_pair(ny,nx));
                v.push_back(make_pair(ny,nx));
                sum+=land[ny][nx];
                cnt++;
            }
        }
    }
    for(int i=0;i<v.size();i++){
        int y=v[i].first;
        int x=v[i].second;
        land[y][x]=sum/cnt;
    }
}
int main(){
    scanf("%d %d %d",&n,&l,&r);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) scanf("%d",&land[i][j]);
    }
    int ans=0;
    while(1){
        if(start()==false) break;
        ans++;
        for(int i=0;i<50;i++) memset(visited[i],0,sizeof(int)*50);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]==0) bfs(i,j);
            }
        }
    }
    printf("%d",ans);
}