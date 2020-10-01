#include <bits/stdc++.h>
using namespace std;
int n,m,k;  //m-상어 수 k-유지 시간
pair<int,int> space[20][20];    //{상어번호, 남은 시간}
deque<pair<int,int>> coordi[401];   //상어가 냄새 뿌린 좌표 {y,x}
int sharkCurDir[401];   //상어 현재 방향
int sharkDirPri[401][16];   //상어 방향 우선순위 (idx0-위/idx4-아래/idx8-왼쪽/idx12-오른쪽)
int dy[5]={0,-1,1,0,0};   //위 아래 왼쪽 오른쪽
int dx[5]={0,0,0,-1,1};
void input(){
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int num;
            scanf("%d",&num);
            if(num>0) coordi[num].push_back({i,j});
            space[i][j]={num,0};
        }
    }
    for(int i=1;i<=m;i++) scanf("%d",&sharkCurDir[i]);
    for(int i=1;i<=m;i++){
        for(int j=0;j<16;j++){
            scanf("%d",&sharkDirPri[i][j]);
        }
    }
}bool inside(int ny,int nx){
    if(ny>=0&&nx>=0&&ny<n&&nx<n) return true;
    return false;
}
vector<int> get_nextDir(int sharkNum, int curDir){
    vector<int> v;
    for(int i=(curDir-1)*4;i<curDir*4;i++) v.push_back(sharkDirPri[sharkNum][i]);
    return v;
}
int solution(){
    int time=0;
    while(1){
        if(time>1000) return -1;
        int cnt=0;  //몇마리 생존했는지 카운트하는 변수
        //냄새뿌림
        for(int i=1;i<=m;i++){
            //시간 줄이기
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(space[j][k].first==i){
                        space[j][k].second--;
                        if(space[j][k].second==0){
                            space[j][k]={0,0};
                            coordi[i].pop_front();
                        }
                    }
                }
            }

            //죽은 상어면 넘어감
            if(sharkCurDir[i]==-1) continue;
            cnt++;
            //현재 좌표와 방향
            int y=coordi[i].back().first;
            int x=coordi[i].back().second;
            int dir=sharkCurDir[i];
            
            //냄새 뿌림
            space[y][x]={i,k};
        }
        if(cnt==1) return time;
        //이동
        for(int i=1;i<=m;i++){
            if(sharkCurDir[i]==-1) continue;
            //현재 상어의 위치와 방향
            int y=coordi[i].back().first;
            int x=coordi[i].back().second;
            int dir=sharkCurDir[i];
            //상어의 방향 우선순위 받아서
            vector<int> dirV=get_nextDir(i,dir);
            bool isEmpty=false;
            int ny,nx,nextDir;
            //우선순위대로 탐색
            //1)빈칸존재하면 이동
            for(int j=0;j<4;j++){
                nextDir=dirV[j];
                ny=y+dy[nextDir];
                nx=x+dx[nextDir];
                if(inside(ny,nx)&&space[ny][nx].first==0){    //아무 냄새가 없는 칸일경우
                    isEmpty=true;
                    break;
                }
            }
            //2)빈칸없을때 자신의 냄새가 존재하는 칸으로 이동
            if(isEmpty==false){
                for(int j=0;j<4;j++){
                    nextDir=dirV[j];
                    ny=y+dy[nextDir];
                    nx=x+dx[nextDir];
                    if(inside(ny,nx)&&space[ny][nx].first==i) break;
                }
            }
            //이동
            coordi[i].push_back({ny,nx});
            sharkCurDir[i]=nextDir;
        }
        //같은 위치에 있는 상어들 체크
        for(int i=1;i<=m;i++){
            if(sharkCurDir[i]==-1) continue;
            for(int j=i+1;j<=m;j++){
                if(sharkCurDir[j]==-1) continue;
                int fY=coordi[i].back().first;
                int fX=coordi[i].back().second;
                int sY=coordi[j].back().first;
                int sX=coordi[j].back().second;
                //같은 위치에 있으면
                if(fY==sY&&fX==sX){
                    if(i<j) sharkCurDir[j]=-1;
                    else sharkCurDir[j]=-1;
                }
            }
        }
        time++;
    }
}
int main(){
    input();
    printf("%d",solution());
}