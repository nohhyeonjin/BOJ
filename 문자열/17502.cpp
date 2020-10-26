#include <bits/stdc++.h>
using namespace std;
int main(){
    int len;
    scanf("%d",&len);
    string s;
    cin >> s;
    int left=0;
    int right=len-1;
    for(;left<=right;left++,right--){
        if(s[left]=='?'&&s[right]=='?'){
            s[left]='a';
            s[right]='a';
            continue;
        }
        if(s[left]=='?'&&s[right]!='?') s[left]=s[right];
        if(s[left]!='?'&&s[right]=='?') s[right]=s[left];
    }
    cout << s;
}