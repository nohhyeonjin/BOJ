#include <iostream>
#include <vector>
using namespace std;
int t,k;
int wheel[1000][8]; //n-0, s-1
vector<pair<int,int>> check(int x, int dir){
    vector<pair<int,int>> v;
    v.push_back({x,dir});
    //왼쪽
    int ldir=dir;
    for(int i=x-1;i>=0;i--){
        if(wheel[i][2]==wheel[i+1][6]) break;
        ldir*=-1;
        v.push_back({i,ldir});
    }
    //오른쪽
    int rdir=dir;
    for(int i=x+1;i<t;i++){
        if(wheel[i][6]==wheel[i-1][2]) break;
        rdir*=-1;
        v.push_back({i,rdir});
    }
    return v;
}
void rotate(int x, int dir){    //시계방향(1), 반시계방향(-1)
    if(dir==1){
        int tmp=wheel[x][7];
        for(int i=7;i>=0;i--) wheel[x][i]=wheel[x][i-1];
        wheel[x][0]=tmp;
    }
    if(dir==-1){
        int tmp=wheel[x][0];
        for(int i=0;i<7;i++) wheel[x][i]=wheel[x][i+1];
        wheel[x][7]=tmp;
    }
}
int main(){
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        for(int j=0;j<8;j++) scanf("%1d",&wheel[i][j]);
    }
    scanf("%d",&k);
    while(k--){
        int num,dir;
        scanf("%d %d",&num,&dir);
        vector<pair<int,int>> v=check(num-1,dir);
        for(int i=0;i<v.size();i++){
            rotate(v[i].first,v[i].second);
        }
    }
    int ans=0;
    for(int i=0;i<t;i++) if(wheel[i][0]==1) ans++;
    printf("%d",ans);
}