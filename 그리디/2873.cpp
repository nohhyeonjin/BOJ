#include <bits/stdc++.h>
using namespace std;
int r,c;
int m[1000][1000];
vector<char> ans;
int main(){
    scanf("%d %d",&r,&c);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++) scanf("%d",&m[i][j]);
    }
    int x=0;
    int y=0;
    if(r%2==1){ //홀x짝, 홀x홀
        for(int i=0;i<r;i++){
            for(int j=0;j<c-1;j++){
                if(i%2==0) ans.push_back('R');
                else ans.push_back('L');
            }
            if(i!=r-1) ans.push_back('D');
        }
    }else if(c%2==1){   //짝x홀
        for(int i=0;i<c;i++){
            for(int j=0;j<r-1;j++){
                if(i%2==0) ans.push_back('D');
                else ans.push_back('U'); 
            }
            if(i!=c-1) ans.push_back('R');
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
            for(int i=0;i<2;i++){
                for(int j=0;j<c-1;j++){
                    if(i%2==0) ans.push_back('R');
                    else ans.push_back('L');
                }
                ans.push_back('D');
            }
            y+=2;
        }
        while(minX-x>=2){
            ans.push_back('D'); ans.push_back('R'); ans.push_back('U'); ans.push_back('R');
            x+=2;
        }
        while(revY-minY>=2){ 
            for(int i=0;i<2;i++){
                for(int j=0;j<c-1;j++){
                    if(i%2==0) reverse.push_back('R');
                    else reverse.push_back('L');
                }
                reverse.push_back('D');
            }
            revY-=2;
        }
        while(revX-minX>=2){
            reverse.push_back('D'); reverse.push_back('R'); reverse.push_back('U'); reverse.push_back('R');
            revX-=2;
        }
        if(x+1==minX){
            ans.push_back('D'); ans.push_back('R');
        }else{
            ans.push_back('R'); ans.push_back('D');
        }
        for(int i=reverse.size()-1;i>=0;i--) ans.push_back(reverse[i]);
    }
    for(int i=0;i<ans.size();i++) printf("%c",ans[i]);
}