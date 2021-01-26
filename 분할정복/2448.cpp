#include <bits/stdc++.h>
using namespace std;
int n;
char pattern[3100][6200];
void star(int y, int x, int size){
    if(size==3){
        pattern[y][x+2]='*';
        pattern[y+1][x+1]=pattern[y+1][x+3]='*';
        for(int i=0;i<5;i++) pattern[y+2][x+i]='*';
        return;
    }
    star(y+size/2,x,size/2);
    star(y+size/2,x+size,size/2);
    star(y,x+size/2,size/2);
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<3100;i++) fill(pattern[i],pattern[i]+6200,' ');
    star(0,0,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<2*n-1;j++) printf("%c",pattern[i][j]);
        printf("\n");
    }
}