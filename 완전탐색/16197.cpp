#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
char pan[20][20];
int dy[4]={0,0,-1,1};
int dx[4]={1,-1,0,0};
bool inside(int y, int x){
    if(y>=0&&x>=0&&y<n&&x<m) return true;
    return false;
}
int ok(vector<pair<int,int>> dol){
    bool first=inside(dol[0].first, dol[0].second);
    bool second=inside(dol[1].first, dol[1].second);
    if(!first&&!second) return -1;
    if(first&&second) return 0;
    if((!first&&second)||(first&&!second)) return 1;
}
int go(int cnt, vector<pair<int,int>> dol){
    if(cnt==11) return -1;
    if(ok(dol)==-1) return -1;
    if(ok(dol)==1) return cnt;
    int ans=-1;
    for(int i=0;i<4;i++){
        vector<pair<int,int>> nextDol;
        for(int j=0;j<2;j++){
            int y=dol[j].first;
            int x=dol[j].second;
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(!inside(ny,nx)) nextDol.push_back({-1,-1});
            else if(pan[ny][nx]=='#') nextDol.push_back({y,x});
            else if(pan[ny][nx]=='.') nextDol.push_back({ny,nx});
        }
        int tmp=go(cnt+1,nextDol);
        if(tmp==-1) continue;
        if(ans==-1||tmp<ans) ans=tmp;
    }
    return ans;
}
int main(){
    cin >> n >> m;
    vector<pair<int,int>> dol;  //{y,x}
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int j=0;j<m;j++){
            if(s[j]=='o'){
                dol.push_back({i,j});
                pan[i][j]='.';
            }else pan[i][j]=s[j];
        }
    }
    cout << go(0,dol);
}