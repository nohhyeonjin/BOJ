#include <iostream>
#include <queue>
#define INF 1e9
using namespace std;
int n,m;
int maze[100][100];
int dist[100][100];
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
bool inside(int y, int x){
    if(y>=0&&x>=0&&y<n&&x<m) return true;
    return false;
}
void dijkstra(){
    priority_queue<pair<int,int>> pq;
    pq.push({0,0});
    dist[0][0]=0;
    while(!pq.empty()){
        int curY=pq.top().first;
        int curX=pq.top().second;
        int cost=dist[curY][curX];
        pq.pop();
        if(dist[curY][curX]<cost) continue;
        for(int i=0;i<4;i++){
            int ny=curY+dy[i];
            int nx=curX+dx[i];
            int nCost=cost+maze[ny][nx];
            if(!inside(ny,nx)) continue;
            if(dist[ny][nx]>nCost){
                dist[ny][nx]=nCost;
                pq.push({ny,nx});
            }
        }
    }
}
int main(){
    scanf("%d %d",&m,&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d",&maze[i][j]);
            dist[i][j]=INF;
        }
    }
    dijkstra();
    printf("%d",dist[n-1][m-1]);
}