#include <bits/stdc++.h>
using namespace std;
int n,m;
int startY,startX;
int dir;  //dir 0-북/1-동/2-남/3-서
int area[50][50];   //0-빈공간 1-벽 2-청소완료
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int ans=1;
void turn_left(){
    if(dir==0) dir=3;
    else dir--;
}
bool notClean(int y,int x){
    int tmpDir=dir;
    if(tmpDir==0) tmpDir=3;
    else tmpDir--;
    int ny=y+dy[tmpDir];
    int nx=x+dx[tmpDir];
    if(area[ny][nx]==0) return true;
    return false;
}
bool inside(int ny, int nx){
    if(ny>=0&&nx>=0&&ny<n&&nx<m) return true;
    return false;
}
void clean(int y, int x){
    //2. 왼쪽방향 탐색
    while(1){
        //2a. 왼쪽방향에 청소하지 않은 공간 존재 시
        if(notClean(y,x)){
            //회전
            turn_left();
            //전진
            int ny=y+dy[dir];
            int nx=x+dx[dir];
            if(inside(ny,nx)){
                //1. 현재위치 청소
                area[ny][nx]=2;
                y=ny;
                x=nx;
                ans++;
            }
        }//2b. 왼쪽방향에 청소할 공간 없으면
        else{
            bool cleanOrWall=true;
            for(int i=0;i<4;i++){
                turn_left();
                int ny=y+dy[dir];
                int nx=x+dx[dir];
                if(inside(ny,nx)&&area[ny][nx]==0) cleanOrWall=false;
            }
            //2c. 네 방향 모두 청소 or 벽인경우
            if(cleanOrWall==true){
                //후진
                int ny=y+(dy[dir]*-1);
                int nx=x+(dx[dir]*-1);
                //후진 불가 시 작동 멈춤
                if(inside(ny,nx)&&area[ny][nx]==1) return;
                y=ny;
                x=nx;
            }else turn_left();
        }
    }
}
int main(){
    scanf("%d %d",&n,&m);
    scanf("%d %d %d",&startY,&startX,&dir);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) scanf("%d",&area[i][j]);
    }
    area[startY][startX]=2;
    clean(startY,startX);
    printf("%d",ans);
}