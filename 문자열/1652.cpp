#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    string s[100];
    int row=0,col=0;
    for(int i=0;i<n;i++) cin >> s[i];
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            if(s[i][j]=='.') cnt++;
            if(s[i][j]=='X'||j==n-1){
                if(cnt>=2) row++;
                cnt=0;
            }
        }
    }
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            if(s[j][i]=='.') cnt++;
            if(s[j][i]=='X'||j==n-1){
                if(cnt>=2) col++;
                cnt=0;
            }
        }
    }
    printf("%d %d",row,col);
}