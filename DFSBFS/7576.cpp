#include <bits/stdc++.h>
using namespace std;
class tomato{
public:
    int h,w,day;
    tomato(int h, int w, int day){
        this->h=h;
        this->w=w;
        this->day=day;
    }
};
int m,n;
int box[1000][1000];
int pushed[1000][1000];
queue<tomato> q;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int bfs(){
    int day;
    while(!q.empty()){
        int y=q.front().h;
        int x=q.front().w;
        day=q.front().day;
        day++;
        q.pop();
        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(ny>=0&&nx>=0&&ny<n&&nx<m&&box[ny][nx]>=0&&pushed[ny][nx]==0){
                box[ny][nx]=day;
                q.push(tomato(ny,nx,day));
                pushed[ny][nx]=1;
            }
        }
    }
    return day;
}
int main(){
    scanf("%d %d",&m,&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&box[i][j]);
            if(box[i][j]==1) q.push(tomato(i,j,0));
        }
    }
    int ans=bfs()-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(box[i][j]==0) ans=-1;
        }
    }
    printf("%d",ans);
}