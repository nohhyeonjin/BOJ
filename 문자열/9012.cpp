#include <bits/stdc++.h>
using namespace std;
int t;
void vps(string s){
    stack<char> st;
    bool vps=true;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(') st.push(s[i]);
        if(s[i]==')'){
            if(!st.empty()) st.pop();
            else{
                vps=false;
                break;
            }
        }
    }
    if(st.size()!=0) vps=false;
    if(vps==true) printf("YES\n");
    else printf("NO\n");
}
int main(){
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        vps(s);
    }
}