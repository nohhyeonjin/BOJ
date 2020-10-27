#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int ans=0;
    scanf("%d",&n);
    while(n--){
        string s;
        cin >> s;
        stack<char> st;
        for(int i=0;i<s.size();i++){
            char cur=s[i];
            char prev;
            if(!st.empty()){
                prev=st.top();
                if(prev==cur) st.pop();
                else st.push(cur);
            }else st.push(cur);
        }
        if(st.empty()) ans++;
    }
    printf("%d",ans);
}