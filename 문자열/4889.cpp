#include <bits/stdc++.h>
using namespace std;
int main(){
    int t=0;
    while(1){
        t++;
        string s;
        cin >> s;
        if(s.find('-')!=string::npos) break;
        int ans=0;
        stack<char> st;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(c=='{'){
                if(i==s.size()-1){
                    st.pop();
                    ans++;
                }else st.push(c);
            }else{
                if(st.empty()){
                    st.push('{');
                    ans++;
                }else st.pop();
            }
        }
        if(!st.empty()) ans+=st.size()/2;
        printf("%d. %d\n",t,ans);
    }
}