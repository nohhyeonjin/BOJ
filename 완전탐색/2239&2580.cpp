#include <bits/stdc++.h>
using namespace std;
int board[9][9];
bool no_duplicate(int y, int x, int num){
    //행확인
    for(int i=0;i<9;i++) if(board[y][i]==num) return false;
    //열확인
    for(int i=0;i<9;i++) if(board[i][x]==num) return false;
    //사각형확인
    for(int i=(y/3)*3;i<(y/3)*3+3;i++){
        for(int j=(x/3)*3;j<(x/3)*3+3;j++) if(board[i][j]==num) return false;
    }
    return true;
}
void solution(int y, int x){
    if(x==9){
        solution(y+1,0);
        return;
    }
    if(y==9){
        //프린트
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++) printf("%d ",board[i][j]);
            printf("\n");
        }
        exit(0);
    }
    if(board[y][x]!=0){
        solution(y,x+1);
        return;
    }
    for(int i=1;i<=9;i++){
        if(no_duplicate(y,x,i)){
            board[y][x]=i;
            solution(y,x+1);
            board[y][x]=0;
        }
    }
}
int main(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++) scanf("%1d",&board[i][j]);
    }
    solution(0,0);
}