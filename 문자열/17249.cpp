//2:11
#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int left=0,right=0;
    int i=0;
    while(1){
        if(s[i]=='(') break;
        if(s[i]=='@') left++;
        i++;
    }
    while(1){
        if(i==s.size()) break;
        if(s[i]=='@') right++;
        i++;
    }
    printf("%d %d",left,right);
}