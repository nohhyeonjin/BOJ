#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        string s;
        list<char> tmp;
        cin >> s;
        list<char>::iterator iter=tmp.end();
        for(int i=0;i<s.size();i++){
            if(s[i]=='<'){
                if(iter!=tmp.begin()) iter--;
            }
            else if(s[i]=='>'){
                if(iter!=tmp.end()) iter++;
            }
            else if(s[i]=='-'){
                if(iter!=tmp.begin()) iter=tmp.erase(--iter); 
            }
            else{
                iter=tmp.insert(iter,s[i]);
                iter++;
            }
        }
        for(iter=tmp.begin();iter!=tmp.end();iter++) cout << *iter;
        printf("\n");
    }
}