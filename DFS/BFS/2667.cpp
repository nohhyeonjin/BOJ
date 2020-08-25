#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
int dy[4]={-1, 1, 0, 0};    //상하좌우
int dx[4]={0, 0, -1, 1};
int map[27][27];
int visited[27][27];
int result[625];
int houseCnt;
int dfs(int y, int x){
    visited[y][x]=1;
    houseCnt++;
    int ny,nx;
    for(int i=0;i<4;i++){
        ny=y+dy[i];
        nx=x+dx[i];
        if(map[ny][nx]==1&&visited[ny][nx]==0) dfs(ny,nx);
    }
    return houseCnt;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%1d",&map[i][j]);
        }
    }
    int groupCnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(map[i][j]==1&&visited[i][j]==0){
                result[groupCnt]=dfs(i,j);
                groupCnt++;
                houseCnt=0;
            }
        }
    }
    printf("%d\n",groupCnt);
    sort(result, result+groupCnt);
    for(int i=0;i<groupCnt;i++) printf("%d\n",result[i]);
}