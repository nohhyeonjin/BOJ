#include <bits/stdc++.h>
using namespace std;
int k;
int main(){
    scanf("%d",&k);
    stack<int> st;
    while(k--){
        int num;
        scanf("%d",&num);
        if(num!=0) st.push(num);
        else st.pop();
    }
    int ans=0;
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    printf("%d",ans);
}