#include <iostream>
#include <algorithm>
using namespace std;
int n;
int dy[5]={0,0,0,-1,1};
int dx[5]={0,-1,1,0,0};
int ground[10][10];
int ans=1e9;
bool selected[10][10];
bool inside(int y, int x){
    if(y>=0&&x>=0&&y<n&&x<n) return true;
    return false;
}
int can_plant(int y, int x){
    int sum=0;
    for(int i=0;i<5;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(!inside(ny,nx)||selected[ny][nx]) return -1;
        sum+=ground[ny][nx];
    }
    return sum;
}
void solve(int y, int x,int cnt,int sum){
    if(sum>ans) return;
    if(cnt==3){
        ans=min(ans,sum);
        return;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int price=can_plant(i,j);
            if(price==-1) continue;
            for(int k=0;k<5;k++){
                int ny=i+dy[k];
                int nx=j+dx[k];
                selected[ny][nx]=true;
            }
            solve(i,j,cnt+1,sum+price);
            for(int k=0;k<5;k++){
                int ny=i+dy[k];
                int nx=j+dx[k];
                selected[ny][nx]=false;
            }
        }
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin >> ground[i][j];
    }
    solve(0,0,0,0);
    cout << ans;
}