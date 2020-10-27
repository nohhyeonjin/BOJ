#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int ans=0;
    stack<char> st;
    char prev=s[0];
    st.push(prev);
    for(int i=1;i<s.size();i++){
        char cur=s[i];
        if(cur=='(') st.push('(');
        else{
            st.pop();
            if(prev=='(') ans+=st.size();
            else ans+=1;
        }
        prev=cur;
    }
    printf("%d",ans);
}