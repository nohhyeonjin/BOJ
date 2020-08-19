#include <bits/stdc++.h>
using namespace std;
int board[100][100];    //1:뱀 2:사과
int dy[]={-1, 0, 1, 0}; //북, 동, 남, 서
int dx[]={0, 1, 0, -1};
int direction=1;
void turn_left(){   //L
    direction--;
    if(direction==-1) direction=3;
}
void turn_right(){  //D
    direction++;
    if(direction==4) direction=0;
}
int main(){
    int n, k, l;
    scanf("%d %d",&n,&k);   //보드크기, 사과개수
    for(int i=0;i<k;i++){
        int y, x;
        scanf("%d %d",&y,&x);
        board[y-1][x-1]=2;
    }
    scanf("%d",&l); //뱀 방향변환횟수
    vector<pair<int, char>> dir;    //방향 변환 정보
    for(int i=0;i<l;i++){
        int sec;
        char rot;
        scanf("%d %c",&sec,&rot);
        dir.push_back(make_pair(sec,rot));
    }
    int time=0;    //시간
    int ny=0, nx=0;
    deque<pair<int,int>> snake;   //뱀 몸 위치
    snake.push_front(make_pair(0,0));
    int dirIdx=0;
    int sec=dir[dirIdx].first;
    char rot=dir[dirIdx].second;
    while(1){
        time++;
        ny=ny+dy[direction];
        nx=nx+dx[direction];
        //벽 또는 뱀 몸통에 부딪히면 stop
        if((ny<0||nx<0||ny>=n||nx>=n)||board[ny][nx]==1) break;

        snake.push_front(make_pair(ny,nx));   
        //사과없을경우
        if(board[ny][nx]!=2){  
            pair<int,int> tail = snake.back();
            snake.pop_back();
            int tailY=tail.first;
            int tailX=tail.second;
            board[tailY][tailX]=0;
        }
        board[ny][nx]=1; 

        //시간이 일치할경우
        if(sec==time){
            if(rot=='L') turn_left();
            if(rot=='D') turn_right();
            dirIdx++;
            sec=dir[dirIdx].first;
            rot=dir[dirIdx].second;
        }
    }
    printf("%d",time);    
}