#include <bits/stdc++.h>
using namespace std;
int wheel[5][8];
int k;
vector<pair<int,int>> v;    //num, dir(1:시계/-1:반시계)
void change(int wheelNum, int dir){
    int tmp[8];
    for(int i=0;i<8;i++) tmp[i]=wheel[wheelNum][i];
    if(dir==1){
        for(int i=1;i<8;i++) wheel[wheelNum][i]=tmp[i-1];
        wheel[wheelNum][0]=tmp[7];
    }
    if(dir==-1){
        for(int i=0;i<7;i++) wheel[wheelNum][i]=tmp[i+1];
        wheel[wheelNum][7]=tmp[0];
    }
}
void rotate(int wheelNum, int dir, int lr){ //lr 0-양쪽 1-오른쪽 2-왼쪽
    int l=wheel[wheelNum][6];
    int r=wheel[wheelNum][2];
    change(wheelNum,dir);
    if(lr==0||lr==1){   //오른쪽
        if(wheelNum+1<=4&&wheel[wheelNum+1][6]!=r) rotate(wheelNum+1,dir*-1,1);
    }
    if(lr==0||lr==2){   //왼쪽
        if(wheelNum-1>=1&&wheel[wheelNum-1][2]!=l) rotate(wheelNum-1,dir*-1,2);
    }
}
int main(){
    for(int i=1;i<5;i++){
        for(int j=0;j<8;j++) scanf("%1d",&wheel[i][j]);
    }
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        int num, dir;
        scanf("%d %d",&num,&dir);
        v.push_back(make_pair(num,dir));
    }
    for(int i=0;i<k;i++){
        int num=v[i].first;
        int dir=v[i].second;
        rotate(num,dir,0);
    }
    int ans=0;
    if(wheel[1][0]==1) ans+=1;
    if(wheel[2][0]==1) ans+=2;
    if(wheel[3][0]==1) ans+=4;
    if(wheel[4][0]==1) ans+=8;
    printf("%d",ans);
}