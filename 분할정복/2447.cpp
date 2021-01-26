#include <bits/stdc++.h>
using namespace std;
int n;
char pattern[3000][3000];
void star(int y, int x, int size){
    if(size==1){
        pattern[y][x]='*';
        return;
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i==1&&j==1) continue;
            star(y+size/3*i,x+size/3*j,size/3);
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<3000;i++) fill(pattern[i],pattern[i]+3000,' ');
    star(0,0,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) printf("%c",pattern[i][j]);
        printf("\n");
    }
}