#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int l,c;
vector<char> ch;
void go(int cnt,string s, int i){
    if(i>c) return;
    if(cnt==l){
        int mo=0, ja=0;
        for(int i=0;i<l;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') mo++;
            else ja++;
        }
        if(mo>=1&&ja>=2) cout << s << "\n";
        return;
    }
    go(cnt+1,s+ch[i],i+1);
    go(cnt,s,i+1);
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> l >> c;
    for(int i=0;i<c;i++){
        char c;
        cin >> c;
        ch.push_back(c);
    }
    sort(ch.begin(),ch.end());
    go(0,"",0);
}