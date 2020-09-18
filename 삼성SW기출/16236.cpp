#include <bits/stdc++.h>
using namespace std;
int n, ans;
int babySize=2;
int babyEatCnt;
int babyPosX, babyPosY;
int space[20][20], visited[20][20], disTable[20][20];
int dy[4]={-1,0,1,0}, dx[4]={0,1,0,-1};
vector<pair<int,int>> fish; //i,j
void input(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int value;
            scanf("%d",&value);
            space[i][j]=value;
            if(value>=1&&value<=6) fish.push_back({i,j});
            if(value==9){
                babyPosX=j;
                babyPosY=i;
            }
        }
    }
}
bool inside(int ny, int nx){
    if(ny>=0&&nx>=0&&ny<n&&nx<n) return true;
    return false;
}
void dfs(){
    for(int i=0;i<n;i++) memset(disTable[i],0,sizeof(int)*n);
    for(int i=0;i<n;i++) memset(visited[i],0,sizeof(int)*n);
    queue<pair<int,int>> q;
    q.push({babyPosY,babyPosX});
    visited[babyPosY][babyPosX]=1;
    disTable[babyPosY][babyPosX]=0;
    while(!q.empty()){
        int y=q.front().first, x=q.front().second;
        int dis=disTable[y][x]+1;
        q.pop();
        for(int i=0;i<4;i++){
            int ny=y+dy[i], nx=x+dx[i];
            if(inside(ny,nx)&&visited[ny][nx]==0&&space[ny][nx]<=babySize){
                q.push({ny,nx});
                visited[ny][nx]=1;
                disTable[ny][nx]=dis;
            }
        }
    }
}
void eat(int y, int x){
    ans+=disTable[y][x];
    space[babyPosY][babyPosX]=0;
    space[y][x]=9;
    babyPosY=y;
    babyPosX=x;
    babyEatCnt++;
    if(babyEatCnt==babySize){
        babySize++;
        babyEatCnt=0;
    }
    //물고기 배열 초기화
    vector<pair<int,int>> tmp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(space[i][j]>=1&&space[i][j]<=6) tmp.push_back({i,j});
        }
    }
    fish=tmp;
}
void move(int y,int x){
    while(1){
        dfs();
        vector<pair<int,int>> smallFish;
        for(int i=0;i<fish.size();i++){
            int y=fish[i].first, x=fish[i].second;
            if(space[y][x]<babySize&&disTable[y][x]!=0) smallFish.push_back({y,x});
        }
        //먹을 수 있는 물고기 없으면
        if(smallFish.size()==0) return;
        //먹을 수 있는 물고기 1마리이면
        if(smallFish.size()==1) eat(smallFish[0].first, smallFish[0].second);
        //1마리 이상이면
        else{
            //가장 가까운 거리 구하고
            int minDis=1e9;
            for(int i=0;i<smallFish.size();i++){
                int y=smallFish[i].first, x=smallFish[i].second;
                minDis=min(minDis,disTable[y][x]);
            }
            vector<pair<int,int>> f;
            for(int i=0;i<smallFish.size();i++){
                int y=smallFish[i].first, x=smallFish[i].second;
                if(disTable[y][x]==minDis) f.push_back({y,x});
            }
            sort(f.begin(),f.end());
            eat(f[0].first,f[0].second);
        }
    }
}
int main(){
    input();
    move(babyPosY,babyPosX);
    printf("%d",ans);
}