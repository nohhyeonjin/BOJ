#include <bits/stdc++.h>
using namespace std;
int earlyS[4][4];
int dy[9]={0,-1,-1,0,1,1,1,0,-1};
int dx[9]={0,0,-1,-1,-1,0,1,1,1};
pair<pair<int,int>,int> earlyF[17]; //{{y,x},dir}
void input(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            int fishNum, fishDir;
            scanf("%d %d",&fishNum,&fishDir);
            earlyF[fishNum]={{i,j},fishDir};
            earlyS[i][j]=fishNum;
        }
    }
}
int ans;
int rotate(int dir){
    if(dir==8) return 1;
    else return dir+1;
}
bool inside(int ny,int nx){
    if(ny>=0&&nx>=0&&ny<4&&nx<4) return true;
    return false;
}
void solution(int y, int x, int sum, int (*s)[4], pair<pair<int,int>,int> *f){
    //복사
    int space[4][4];
    pair<pair<int,int>,int> fish[17];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++) space[i][j]=s[i][j];
    }
    for(int i=0;i<17;i++) fish[i]=f[i];

    //상어 먹음
    int fishNum=space[y][x];
    int fishDir=fish[fishNum].second;
    fish[0]={{y,x},fishDir};    //상어 정보 갱신
    space[y][x]=0;  //먹힌 장소 0으로 표시
    fish[fishNum]={{-1,-1},-1}; //먹힌 물고기 정보 갱신
    sum+=fishNum;
    ans=max(ans,sum);

    //물고기 이동
    for(int i=1;i<=16;i++){
        //물고기 정보
        int fishDir=fish[i].second;
        if(fishDir==-1) continue;   //이미 먹힌 물고기라면 넘어감
        int fishY=fish[i].first.first;
        int fishX=fish[i].first.second;
        for(int j=0;j<8;j++){
            int ny=fishY+dy[fishDir];
            int nx=fishX+dx[fishDir];
            //영역 벗어나거나 상어있으면 45도 반시계 회전
            if(!inside(ny,nx)||(ny==y&&nx==x)) fishDir=rotate(fishDir);
            else{
                //물고기 swap
                int objNum=space[ny][nx];
                fish[i]={{ny,nx},fishDir};
                fish[objNum]={{fishY,fishX},fish[objNum].second};
                swap(space[ny][nx],space[fishY][fishX]);
                break;
            }
        }
    }
    
    //상어 이동
    int ny=y+dy[fishDir];
    int nx=x+dx[fishDir];
    for(int i=0;i<3;i++){
        if(inside(ny,nx)&&space[ny][nx]!=0) solution(ny,nx,sum,space,fish);
        ny+=dy[fishDir];
        nx+=dx[fishDir];
    }
}
int main(){
    input();
    solution(0,0,0,earlyS,earlyF);
    printf("%d",ans);
}