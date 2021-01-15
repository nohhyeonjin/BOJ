#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string a,b,c,d;
    cin >> a >> b >> c >> d;
    string ab=a+b;
    string cd=c+d;
    cout << stoll(ab)+stoll(cd);
}