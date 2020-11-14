#include <bits/stdc++.h>
#define MAX 125
#define INF 1e9
using namespace std;
int n,ans;
int arr[MAX][MAX];
int table[MAX][MAX];
int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};
bool inside(int ny,int nx){
    if(ny>=0&&nx>=0&&ny<n&&nx<n) return true;
    return false;
}
void dijkstra(int y, int x){
    priority_queue<pair<int,pair<int,int>>> pq; //{cost,{y,x}}
    pq.push({-arr[y][x],{y,x}});
    table[y][x]=arr[y][x];
    while(!pq.empty()){
        int dist=-pq.top().first;
        int y=pq.top().second.first;
        int x=pq.top().second.second;
        pq.pop();
        if(table[y][x]<dist) continue;
        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(!inside(ny,nx)) continue;
            int cost=dist+arr[ny][nx];
            if(cost<table[ny][nx]){
                table[ny][nx]=cost;
                pq.push({-cost,{ny,nx}});
            }
        }
    }
}
int main(){
    int num=1;
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&arr[i][j]);
                table[i][j]=INF;
            }
        }
        dijkstra(0,0);
        ans=table[n-1][n-1];
        printf("Problem %d: %d\n",num,ans);
        num++;
    }
}