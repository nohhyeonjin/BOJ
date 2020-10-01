#include <bits/stdc++.h>
using namespace std;
int n,m;
int paper[500][500];
int ans;
pair<int,int> polyomino[19][4]={
    //긴거
    {{0,0},{0,1},{0,2},{0,3}},
    {{0,0},{1,0},{2,0},{3,0}},
    //네모난거
    {{0,0},{0,1},{1,0},{1,1}},
    //ㄴ
    {{0,0},{1,0},{2,0},{2,1}},
    {{0,1},{1,1},{2,1},{2,0}},
    {{0,0},{0,1},{0,2},{1,0}},
    {{0,0},{0,1},{0,2},{1,2}},
    {{0,0},{0,1},{1,1},{2,1}},
    {{0,0},{1,0},{2,0},{0,1}},
    {{1,0},{1,1},{1,2},{0,2}},
    {{0,0},{1,0},{1,1},{1,2}},
    //ㅗ
    {{0,0},{0,1},{0,2},{1,1}},
    {{1,0},{0,1},{1,1},{2,1}},
    {{1,0},{1,1},{1,2},{0,1}},
    {{0,0},{1,0},{2,0},{1,1}},
    //s
    {{0,0},{1,0},{1,1},{2,1}},
    {{0,1},{1,0},{1,1},{2,0}},
    {{1,0},{1,1},{0,1},{0,2}},
    {{0,0},{0,1},{1,1},{1,2}}
};
bool inside(int ny, int nx){
    if(ny>=0&&nx>=0&&ny<n&&nx<m) return true;
    return false;
}
void solution(){
    for(int i=0;i<19;i++){
        for(int y=0;y<n;y++){
            for(int x=0;x<m;x++){
                int sum=0;
                bool in=true;
                for(int k=0;k<4;k++){
                    int ny=y+polyomino[i][k].first;
                    int nx=x+polyomino[i][k].second;
                    if(inside(ny,nx)) sum+=paper[ny][nx];
                    else{
                        in=false;
                        break;
                    }
                }
                if(in==true) ans=max(ans,sum);
            }
        }
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) scanf("%d",&paper[i][j]);
    }
    solution();
    printf("%d",ans);
}