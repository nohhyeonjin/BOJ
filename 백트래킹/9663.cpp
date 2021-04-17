#include <iostream>
using namespace std;
int n;
bool selectedCol[15];
bool selectedDig[30];
bool selectedDig2[30];
bool chk(int y, int x){
    if(selectedCol[x]) return false;
    if(selectedDig[y+x]) return false;
    if(selectedDig2[n+y-x]) return false;
    return true;
}
int go(int row){
    if(row==n) return 1;
    int ans=0;
    for(int i=0;i<n;i++){
        if(!chk(row,i)) continue;
        selectedCol[i]=true;
        selectedDig[row+i]=true;
        selectedDig2[n+row-i]=true;
        ans+=go(row+1);
        selectedCol[i]=false;
        selectedDig[row+i]=false;
        selectedDig2[n+row-i]=false;
    }
    return ans;
}
int main(){
    scanf("%d",&n);
    printf("%d",go(0));
}