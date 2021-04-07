#include <iostream>
#include <limits.h>
using namespace std;
int n,m,k;
int ans=INT_MIN;
int dy[4]={0,0,1,-1};
int dx[4]={1,-1,0,0};
int arr[10][10];
bool chk[10][10];
bool inside(int ny, int nx){
    if(ny>=0&&nx>=0&&ny<n&&nx<m) return true;
    return false;
}
void go(int y, int x, int sum, int cnt){
    if(cnt==k){
        if(sum>ans) ans=sum;
        return;
    }
    for(int i=y;i<n;i++){
        for(int j=(i==y?x:0);j<m;j++){
            if(chk[i][j]) continue;
            bool ok=true;
            for(int k=0;k<4;k++){
                int ny=i+dy[k];
                int nx=j+dx[k];
                if(!inside(ny,nx)) continue;
                if(chk[ny][nx]){
                    ok=false;
                    break;
                }
            }
            if(ok){
                chk[i][j]=true;
                go(i,j,sum+arr[i][j],cnt+1);
                chk[i][j]=false;
            }
        }
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
    go(0,0,0,0);
    cout << ans;
}