#include <bits/stdc++.h>
using namespace std;
int ans;
int main(){
    string s[8];
    for(int i=0;i<8;i++) cin >> s[i];
    for(int i=0;i<8;i+=2){
        for(int j=0;j<8;j+=2) if(s[i][j]=='F') ans++;
    }
    for(int i=1;i<8;i+=2){
        for(int j=1;j<8;j+=2) if(s[i][j]=='F') ans++;
    }
    printf("%d",ans);
}