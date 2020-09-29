#include <bits/stdc++.h>
using namespace std;
int alpha[26];
int main(){
    string s;
    cin >> s;
    fill(alpha,alpha+26,-1);
    for(int i=0;i<s.size();i++){
        if(alpha[s[i]-'a']==-1) alpha[s[i]-'a']=i;
    }
    for(int i=0;i<26;i++) printf("%d ",alpha[i]);
}