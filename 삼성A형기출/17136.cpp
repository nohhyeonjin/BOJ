#include <bits/stdc++.h>
using namespace std;
int area[10][10];
vector<pair<int,int>> paper[6];
int paperCnt[6]={0,5,5,5,5,5};
int ans=1e9;
void input(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++) scanf("%d",&area[i][j]);
    }
}
void init_paper(){
    for(int i=1;i<=5;i++){
        for(int j=0;j<i;j++){
            for(int k=0;k<i;k++) paper[i].push_back({j,k});
        }
    }
}
bool inside(int ny,int nx){
    if(ny>=0&&nx>=0&&ny<10&&nx<10) return true;
    return false;
}
bool done(int (*area)[10]){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(area[i][j]==1) return false;
        }
    }
    return true;
}
pair<int,int> get_position(int (*area)[10]){
    int y,x;
    if(done(area)) return {-1,-1};
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(area[i][j]==1) return {i,j};
        }
    }
}
bool can_attach(int y, int x, int s, int (*area)[10]){
    //붙일 수 있는지 확인
    for(int i=0;i<paper[s].size();i++){
        int ny=y+paper[s][i].first;
        int nx=x+paper[s][i].second;
        if(!inside(ny,nx)||area[ny][nx]==0) return false;
    }
    return true;
}
void dfs(int cnt, int (*area)[10]){
    //가지치기
    if(cnt>ans) return;
    //기저조건
    if(done(area)){
        ans=min(ans,cnt);
        return;
    }
    //색종이 붙이기
    for(int s=5;s>0;s--){
        if(paperCnt[s]==0) continue;
        pair<int,int> pos=get_position(area);
        if(!can_attach(pos.first,pos.second,s,area)) continue;
        //붙이기
        paperCnt[s]--;
        for(int i=0;i<paper[s].size();i++){
            int ny=pos.first+paper[s][i].first;
            int nx=pos.second+paper[s][i].second;
            area[ny][nx]=0;
        }
        dfs(cnt+1,area);
        //떼기
        for(int i=0;i<paper[s].size();i++){
            int ny=pos.first+paper[s][i].first;
            int nx=pos.second+paper[s][i].second;
            area[ny][nx]=1;
        }
        paperCnt[s]++;
    }
}
int main(){
    input();
    init_paper();
    dfs(0,area);
    if(ans==1e9) printf("-1");
    else printf("%d",ans);
}