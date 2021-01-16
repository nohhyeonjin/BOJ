#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,b;
    scanf("%d %d",&n,&b);
    stack<int> st;
    while(1){
        int x=n/b;
        int y=n%b;
        st.push(y);
        if(x==0) break;
        n=x;
    }
    while(!st.empty()){
        if(st.top()<10) printf("%d",st.top());
        else printf("%c",st.top()-10+'A');
        st.pop();
    }
}