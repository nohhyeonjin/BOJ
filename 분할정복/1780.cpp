#include <bits/stdc++.h>
using namespace std;
int n;
int paper[2200][2200];
int a,b,c;
bool check(int y, int x, int size){
    int num=paper[y][x];
    for(int i=y;i<y+size;i++){
        for(int j=x;j<x+size;j++){
            if(paper[i][j]!=num) return false;
        }
    }
    return true;
}
void divide(int y, int x, int size){
    bool isSame=check(y,x,size);
    if(isSame){
        int num=paper[y][x];
        if(num==-1) a++;
        if(num==0) b++;
        if(num==1) c++;
        return;
    }else{
        for(int i=y;i<y+size;i+=size/3){
            for(int j=x;j<x+size;j+=size/3) divide(i,j,size/3);
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) scanf("%d",&paper[i][j]);
    }
    divide(0,0,n);
    printf("%d\n%d\n%d",a,b,c);
}