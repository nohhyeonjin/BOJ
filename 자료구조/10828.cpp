#include <bits/stdc++.h>
using namespace std;
stack<int> st;
int main(){
    int t;
    scanf("%d",&t);
    getchar();
    while(t--){
        string s;
        getline(cin,s);
        stringstream ss(s);
        string oper;
        int num;
        ss >> oper >> num;
        if(oper=="push") st.push(num);
        if(oper=="pop"){
            if(st.empty()) printf("-1\n");
            else{    
                printf("%d\n",st.top());
                st.pop();
            }
        }
        if(oper=="size") printf("%d\n",st.size());
        if(oper=="empty"){
            if(st.empty()) printf("1\n");
            else printf("0\n");
        }
        if(oper=="top"){
            if(st.empty()) printf("-1\n");
            else printf("%d\n",st.top());
        }
    }
}