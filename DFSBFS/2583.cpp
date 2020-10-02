#include <bits/stdc++.h>
using namespace std;
int m,n,k;
int arr[100][100], visited[100][100];
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int component;
vector<int> area;
bool inside(int ny, int nx){
    if(ny>=0&&nx>=0&&ny<m&&nx<n) return true;
    return false;
}
void bfs(int y, int x){
    int sum=1;
    queue<pair<int,int>> q;
    q.push({y,x});
    visited[y][x]=1;
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(inside(ny,nx)&&arr[ny][nx]==0&&visited[ny][nx]==0){
                q.push({ny,nx});
                visited[ny][nx]=1;
                sum++;
            }
        }
    }
    area.push_back(sum);
}
int main(){
    scanf("%d %d %d",&m,&n,&k);
    for(int i=0;i<k;i++){
        int x1,x2,y1,y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        for(int h=m-y2;h<m-y1;h++){
            for(int w=x1;w<x2;w++) arr[h][w]=1;
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==0&&visited[i][j]==0){
                bfs(i,j);
                component++;
            }
        }
    }
    printf("%d\n",component);
    sort(area.begin(),area.end());
    for(int i=0;i<area.size();i++) printf("%d ",area[i]);
}