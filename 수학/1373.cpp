#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    string s;
    cin >> s;
    stack<int> st;
    for(int i=s.size()-1;i>=0;i-=3){
        int sum=0;
        for(int j=0;j<3;j++){
            if(i-j<0) break;
            sum+=((s[i-j]-'0')*pow(2,j));
        }
        st.push(sum);
    }
    while(!st.empty()){
        printf("%d",st.top());
        st.pop();
    }
}