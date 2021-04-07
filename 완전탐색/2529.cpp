#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int k;
vector<string> ans;
char c[9];
bool chk[10];
bool ok(string s){
    for(int i=0;i<k;i++){
        int a=s[i]-'0';
        int b=s[i+1]-'0';
        if(c[i]=='<'){
            if(a>b) return false;
        }
        if(c[i]=='>'){
            if(a<b) return false;
        }
    }
    return true;
}
void go(int idx, string s){
    if(s.size()==k+1){
        if(ok(s)) ans.push_back(s);
        return;
    }
    for(int i=0;i<10;i++){
        if(chk[i]) continue;
        chk[i]=true;
        go(idx+1,s+to_string(i));
        chk[i]=false;
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> k;
    for(int i=0;i<k;i++) cin >> c[i];
    go(0,"");
    auto p = minmax_element(ans.begin(),ans.end());
    cout << *p.second << "\n" << *p.first;
}