#include <iostream>
using namespace std;
int h,w,x,y;
int a[300][300], b[600][600];
bool inA(int i, int j){
    if(i>=0&&i<h&&j>=0&&j<w) return true;
    return false;
}
bool inC(int i, int j){
    if(i>=x&&i<x+h&&j>=y&&j<w+y) return true;
    return false;
}
int main(){
    scanf("%d %d %d %d",&h,&w,&x,&y);
    for(int i=0;i<h+x;i++){
        for(int j=0;j<w+y;j++) scanf("%d",&b[i][j]);
    }
    for(int i=0;i<h+x;i++){
        for(int j=0;j<w+y;j++){
            if(inA(i,j)&&!inC(i,j)) a[i][j]=b[i][j];
            if(!inA(i,j)&&inC(i,j)) a[i-x][j-y]=b[i][j];
            if(inA(i,j)&&inC(i,j)) a[i][j]=b[i][j]-a[i-x][j-y];
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++) printf("%d ",a[i][j]);
        printf("\n");
    }
}