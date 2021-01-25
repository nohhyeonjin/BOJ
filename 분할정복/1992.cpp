#include <bits/stdc++.h>
using namespace std;
int n;
int video[64][64];
bool check(int y, int x, int size){
    int num=video[y][x];
    for(int i=y;i<y+size;i++){
        for(int j=x;j<x+size;j++){
            if(num!=video[i][j]) return false;
        }
    }
    return true;
}
void compression(int y, int x, int size){
    bool isSame=check(y,x,size);
    if(isSame){
        printf("%d",video[y][x]);
    }else{
        printf("(");
        int newSize=size/2;
        compression(y,x,newSize);
        compression(y,x+newSize,newSize);
        compression(y+newSize,x,newSize);
        compression(y+newSize,x+newSize,newSize);
        printf(")");
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) scanf("%1d",&video[i][j]);
    }
    compression(0,0,n);
}