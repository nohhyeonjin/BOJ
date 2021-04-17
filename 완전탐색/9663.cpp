#include <iostream>
using namespace std;
int n;
bool selected[15][15];
bool chk_col(int x){
    for(int i=0;i<n;i++) if(selected[i][x]) return false;
    return true;
}
bool chk_diagonal(int y, int x){
    int i=y,j=x;
    while(i>=0&&j>=0){
        if(selected[i][j]) return false;
        i--; j--;
    }
    i=y; j=x;
    while(i>=0&&j<n){
        if(selected[i][j]) return false;
        i--; j++;
    }
    return true;
}
int go(int row){
    if(row==n) return 1;
    int ans=0;
    for(int j=0;j<n;j++){
        if(!(chk_col(j)&&chk_diagonal(row,j))) continue;
        selected[row][j]=true;
        ans+=go(row+1);
        selected[row][j]=false;    
    }
    return ans;
}
int main(){
    scanf("%d",&n);
    printf("%d",go(0));
}