#include <bits/stdc++.h>
using namespace std;
int n;
bool compare(string a, string b){
    int aSize=a.size();
    int bSize=b.size();
    if(aSize==bSize) return a<b;
    return aSize<bSize; //앞에꺼 사이즈가 뒤에꺼 사이즈보다 작게
}
vector<string> words;
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        words.push_back(s);
    }
    sort(words.begin(),words.end(),compare);
    cout << words[0] << "\n";
    string cur=words[0];
    for(int i=1;i<n;i++){
        if(cur==words[i]) continue;
        cout << words[i] << "\n";
        cur=words[i];
    }
}