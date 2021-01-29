#include <bits/stdc++.h>
using namespace std;
int r,c;
int m[1000][1000];
int dy[4]={0,1,0,-1};   //오른쪽, 아래, 왼쪽, 위
int dx[4]={1,0,-1,0};
vector<char> ans;
int main(){
    scanf("%d %d",&r,&c);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++) scanf("%d",&m[i][j]);
    }
    int x=0;
    int y=0;
    if(r%2==1){ //홀x짝, 홀x홀
        int dir=0;
        while(1){
            y+=dy[dir]*(c-1);
            x+=dx[dir]*(c-1);
            if(dir==0){ //오른쪽으로 쭉
                dir=2;
                for(int i=0;i<c-1;i++) ans.push_back('R');
            }
            else if(dir==2){    //왼쪽으로 쭉
                dir=0;
                for(int i=0;i<c-1;i++) ans.push_back('L');
            }
            if(y==r-1&&x==c-1) break;
            //아래방향
            y+=dy[1];
            x+=dx[1];
            ans.push_back('D');
        }
    }else if(c%2==1){   //짝x홀
        int dir=1;
        while(1){
            y+=dy[dir]*(r-1);
            x+=dx[dir]*(r-1);
            if(dir==1){ //아래로 쭉
                dir=3;
                for(int i=0;i<r-1;i++) ans.push_back('D');
            }
            else if(dir==3){    //위로 쭉
                dir=1;
                for(int i=0;i<r-1;i++) ans.push_back('U');
            }
            if(y==r-1&&x==c-1) break;
            //오른쪽방향
            y+=dy[0];
            x+=dx[0];
            ans.push_back('R');
        }
    }else{  //짝x짝
        int minValue=1000;
        int minX, minY;
        vector<int> reverse;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(((i+j)%2==1)&&(minValue>m[i][j])){
                    minValue=m[i][j];
                    minX=j; minY=i;
                }
            }
        }
        int revX=c-1, revY=r-1;
        while(minY-y>=2){
            for(int i=0;i<c-1;i++) ans.push_back('R');
            ans.push_back('D');
            for(int i=0;i<c-1;i++) ans.push_back('L');
            ans.push_back('D');
            y+=2;
        }
        while(minX-x>=2){
            ans.push_back('D'); ans.push_back('R'); ans.push_back('U'); ans.push_back('R');
            x+=2;
        }
        while(revY-minY>=2){ //L은 R로, U은 D로 나중에 뒤집기 
            for(int i=0;i<c-1;i++) reverse.push_back('L');
            reverse.push_back('U');
            for(int i=0;i<c-1;i++) reverse.push_back('R');
            reverse.push_back('U');
            revY-=2;
        }
        while(revX-minX>=2){    //U<->D L<->R
            reverse.push_back('U'); reverse.push_back('L'); reverse.push_back('D'); reverse.push_back('L');
            revX-=2;
        }
        if(x+1==minX){
            ans.push_back('D'); ans.push_back('R');
        }else{
            ans.push_back('R'); ans.push_back('D');
        }
        for(int i=reverse.size()-1;i>=0;i--){
            char c=reverse[i];
            if(c=='U') ans.push_back('D');
            if(c=='D') ans.push_back('U');
            if(c=='R') ans.push_back('L');
            if(c=='L') ans.push_back('R');
        }
    }
    for(int i=0;i<ans.size();i++) printf("%c",ans[i]);
}