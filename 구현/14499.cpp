#include <iostream>
using namespace std;
int n,m,x,y,k;
int pan[20][20];
int dice[7];
int dy[4]={0,0,-1,1};
int dx[4]={1,-1,0,0};
bool inside(int ny, int nx){
    if(ny>=0&&nx>=0&&ny<n&&nx<m) return true;
    return false;
}
void go(int order){
    int ny=y+dy[order-1];
    int nx=x+dx[order-1];
    if(!inside(ny,nx)) return;

    //굴림
    if(order==1){   //동
        int tmp=dice[1];
        dice[1]=dice[4];
        dice[4]=dice[6];
        dice[6]=dice[3];
        dice[3]=tmp;
    }
    if(order==2){   //서
        int tmp=dice[1];
        dice[1]=dice[3];
        dice[3]=dice[6];
        dice[6]=dice[4];
        dice[4]=tmp;
    }
    if(order==3){   //북
        int tmp=dice[1];
        dice[1]=dice[5];
        dice[5]=dice[6];
        dice[6]=dice[2];
        dice[2]=tmp;   
    }
    if(order==4){   //남
        int tmp=dice[1];
        dice[1]=dice[2];
        dice[2]=dice[6];
        dice[6]=dice[5];
        dice[5]=tmp;    
    }

    //이동
    if(pan[ny][nx]==0) pan[ny][nx]=dice[6];
    else{
        dice[6]=pan[ny][nx];
        pan[ny][nx]=0;
    }
    y=ny;
    x=nx;
    printf("%d\n",dice[1]);
}
int main(){
    scanf("%d %d %d %d %d",&n,&m,&y,&x,&k);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) scanf("%d",&pan[i][j]);
    }
    for(int i=0;i<k;i++){
        int order;
        scanf("%d",&order);
        go(order);
    }
}