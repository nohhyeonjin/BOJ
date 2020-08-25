#include <bits/stdc++.h>
using namespace std;
int n;
char hall[7][7];
int dy[4]={0,-1,0,1};
int dx[4]={1,0,-1,0};
vector<pair<int,int>> teacher;
bool ans=false;
void input(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>hall[i][j];
            if(hall[i][j]=='T') teacher.push_back(make_pair(i,j));
        }
    }
}
bool watch(){
    for(int i=0;i<teacher.size();i++){
        int y=teacher[i].first;
        int x=teacher[i].second;
        for(int k=0;k<4;k++){
            int ny=y+dy[k];
            int nx=x+dx[k];
            while(ny>0&&ny<=n&&nx>0&&nx<=n){
                if(hall[ny][nx]=='O') break;
                if(hall[ny][nx]=='S') return false;
                ny=ny+dy[k];
                nx=nx+dx[k];
            }
        }
    }
    return true;
}
void make_wall(int cnt){
    if(cnt==3){
        if(watch()) ans=true;
        return;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(hall[i][j]=='X'){
                hall[i][j]='O';
                cnt++;
                make_wall(cnt);
                hall[i][j]='X';
                cnt--;
            }
        }
    }
}
int main(){
    input();
    make_wall(0);
    if(ans==true) printf("YES");
    else printf("NO");
}