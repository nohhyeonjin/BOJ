#include <stdio.h>
#include <string.h>
using namespace std;
int ground[52][52];
int visited[52][52];
void dfs(int h, int w){
    visited[h][w]=1;
    for(int i=h-1;i<=h+1;i++){
        for(int j=w-1;j<=w+1;j++){
            if(ground[i][j]==1&&visited[i][j]==0) dfs(i,j);
        }
    }
}
int main(){
    int w,h;
    while(1){
        scanf("%d %d",&w,&h);
        if(w==0&&h==0) break;
        for(int i=0;i<52;i++){
            memset(ground[i],0,sizeof(int)*52);
            memset(visited[i],0,sizeof(int)*52);
        }
        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++) scanf("%d",&ground[i][j]);
        }
        int answer=0; 
        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++) {
                if(ground[i][j]==1&&visited[i][j]==0){
                    answer++;
                    dfs(i,j);
                }
            }
        }
        printf("%d\n",answer);
    }
}