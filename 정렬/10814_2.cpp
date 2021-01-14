#include <bits/stdc++.h>
using namespace std;
bool compare(pair<pair<int,string>,int> a, pair<pair<int,string>,int> b){
    if(a.first.first==b.first.first) return a.second < b.second;
    return a.first.first<b.first.first;
}
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<pair<int,string>,int>> member;
    for(int i=0;i<n;i++){
        int age;
        string name;
        cin >> age >> name;
        member.push_back({{age,name},i});
    }
    sort(member.begin(),member.end(),compare);
    for(int i=0;i<n;i++) cout << member[i].first.first << " " << member[i].first.second << "\n";
}