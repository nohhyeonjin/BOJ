#include <bits/stdc++.h>
using namespace std;
int chk[26];
bool isOK(string s){
    int len=s.length();
    int i=0;
    while(i<len){
        int idx=s[i]-'A';
        chk[idx]++;
        if(chk[idx]==3){
            if(s[i+1]-'A'!=idx) return false;
            chk[idx]=0;
            i+=2; 
        }
        else i++;
    }
    return true;
}
int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        string s;
        cin >> s;
        memset(chk,0,sizeof(int)*26);
        bool ans=isOK(s);
        if(ans==true) cout << "OK" << "\n";
        else cout << "FAKE" << "\n";
    }
}