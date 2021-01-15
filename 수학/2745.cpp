#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string n;
    int b;
    cin >> n >> b;
    int ans=0;
    int mul=0;
    for(int i=n.size()-1;i>=0;i--){
        int num;
        if(isalpha(n[i])) num=n[i]-'A'+10;
        else num=n[i]-'0';
        ans+=(num*pow(b,mul++));
    }
    cout << ans;
}