#include <bits/stdc++.h>
using namespace std;
int r,c,t;
vector<int> airPos; //공기청정기의 y 
vector<pair<pair<int,int>,pair<int,int>>> dust; //{{y,x},{center,side}}
int room[50][50];
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
bool inside(int ny,int nx){
    if(ny>=0&&nx>=0&&ny<r&&nx<c) return true;
    return false;
}
bool can_spread(int ny,int nx){
    //방안이면서 공기청정기가 있는곳이 아니라면 return true
    if(inside(ny,nx)&&room[ny][nx]!=-1) return true;
    return false;
}
void input(){
    scanf("%d %d %d",&r,&c,&t);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            int n;
            scanf("%d",&n);
            if(n==-1) airPos.push_back(i);
            if(n>0) dust.push_back({{i,j},{n,0}});
            room[i][j]=n;
        }
    }
}
void cal_spread(){
    for(int i=0;i<dust.size();i++){
        int cost=dust[i].second.first;
        int y=dust[i].first.first;
        int x=dust[i].first.second;
        int spreadCnt=0;
        //네방향 확인
        for(int j=0;j<4;j++){
            int ny=y+dy[j];
            int nx=x+dx[j];
            if(can_spread(ny,nx)) spreadCnt++;
        }
        //퍼져야할 양 계산
        int side=cost/5;
        int center=cost-side*spreadCnt;
        dust[i].second.first=center;
        dust[i].second.second=side;
    }
}
void spread(){
    //중앙과 네방향 0으로 초기화
    for(int i=0;i<dust.size();i++){
        int y=dust[i].first.first;
        int x=dust[i].first.second;
        room[y][x]=0;
        for(int j=0;j<4;j++){
            int ny=y+dy[j];
            int nx=x+dx[j];
            if(can_spread(ny,nx)) room[ny][nx]=0;
        }
    }
    //퍼트리기
    for(int i=0;i<dust.size();i++){
        int y=dust[i].first.first;
        int x=dust[i].first.second;
        int center=dust[i].second.first;
        int side=dust[i].second.second;
        //중앙
        room[y][x]+=center;
        //사이드
        for(int j=0;j<4;j++){
            int ny=y+dy[j];
            int nx=x+dx[j];
            if(can_spread(ny,nx)) room[ny][nx]+=side;
        }
    }
}
void work(){
    int upPos=airPos[0];
    int downPos=airPos[1];
    //위쪽
    for(int i=upPos-1;i>=0;i--) room[i][0]=room[i-1][0];
    for(int i=0;i<c-1;i++) room[0][i]=room[0][i+1];
    for(int i=0;i<upPos;i++) room[i][c-1]=room[i+1][c-1];
    for(int i=c-1;i>=2;i--) room[upPos][i]=room[upPos][i-1];
    room[upPos][1]=0;
    //아래쪽
    for(int i=downPos+1;i<r-1;i++) room[i][0]=room[i+1][0];
    for(int i=0;i<c-1;i++) room[r-1][i]=room[r-1][i+1];
    for(int i=r-1;i>downPos;i--) room[i][c-1]=room[i-1][c-1];
    for(int i=c-1;i>=2;i--) room[downPos][i]=room[downPos][i-1];
    room[downPos][1]=0;
    //먼지 정보 초기화
    vector<pair<pair<int,int>,pair<int,int>>> newDust;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(room[i][j]>0) newDust.push_back({{i,j},{room[i][j],0}});
        }
    }
    dust=newDust;
}
int cal_dustCost(){
    int cnt=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(room[i][j]>0) cnt+=room[i][j];
        }
    }
    return cnt;
}
int main(){
    input();
    int cnt=0;
    while(t--){
        cal_spread();
        spread();
        work();
    }
    printf("%d",cal_dustCost());
}