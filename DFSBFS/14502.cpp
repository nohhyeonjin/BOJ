#include <bits/stdc++.h>
using namespace std;
int n,m;
int mp[9][9];   //원본
int tmp[9][9];  //가상으로 벽세운 복사본
int dy[4]={0,-1,0,1};   //동 북 서 남
int dx[4]={1,0,-1,0};
int ans;
vector<pair<int,int>> virus;
void input(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&mp[i][j]);
            if(mp[i][j]==2) virus.push_back(make_pair(i,j));
        }
    }
}
void spread_virus(int y,int x){
    queue<pair<int,int>> q;
    q.push(make_pair(y,x));
    while(!q.empty()){
        pair<int,int> cur=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int ny=cur.first+dy[i];
            int nx=cur.second+dx[i];
            if(ny>0&&ny<=n&&nx>0&&nx<=m&&tmp[ny][nx]==0){
                tmp[ny][nx]=2;
                q.push(make_pair(ny,nx));
            }
        }
    }
}
int count_safe(){
    int safeCnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(tmp[i][j]==0) safeCnt++;
        }
    }
    return safeCnt;
}
void make_wall(int cnt){
    if(cnt==3){
        for(int i=1;i<=n;i++){  //지도 복사
            for(int j=1;j<=m;j++) tmp[i][j]=mp[i][j];
        }
        for(int i=0;i<virus.size();i++){
            spread_virus(virus[i].first,virus[i].second);
        }
        ans=max(ans,count_safe());
        return;
    }
    for(int i=1;i<=n;i++){  //벽 세우는 조합
        for(int j=1;j<=m;j++){
            if(mp[i][j]==0){
                mp[i][j]=1;
                cnt++;
                make_wall(cnt);
                mp[i][j]=0;
                cnt--;
            }
        }
    }
}
int main(){
    input();
    make_wall(0);
    printf("%d",ans);
}