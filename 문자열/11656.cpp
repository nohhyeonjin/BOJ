#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    vector<string> v;
    for(int i=0;i<s.size();i++){
        string ns;
        for(int j=i;j<s.size();j++) ns+=s[j];
        v.push_back(ns);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++) cout << v[i] << "\n";
}