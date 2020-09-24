#include <bits/stdc++.h>
using namespace std;
string s;
int ans;
string croatia[8]={"c=","c-","dz=","d-","lj","nj","s=","z="};
int main(){
    cin >> s;
    for(int i=0;i<8;i++){
        while(1){
            //찾았으면
            if(s.find(croatia[i])!=string::npos){
                ans++;
                int idx=s.find(croatia[i]);
                int size=croatia[i].size();
                s.replace(idx,size,"1");
            }else break;    
        }
    }
    for(int i=0;i<s.size();i++) if(!isdigit(s[i])) ans++;
    printf("%d",ans);
}