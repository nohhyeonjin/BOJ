#include <bits/stdc++.h>
using namespace std;
int n,m;
map<string, int> mp;
string num[100001];
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        string s;
        cin >> s;
        mp[s]=i;
        num[i]=s;
    }
    for(int i=0;i<m;i++){
        string s;
        cin >> s;
        if(isdigit(s[0])) cout << num[stoi(s)] << "\n";
        else cout << mp[s] << "\n";
    }
}