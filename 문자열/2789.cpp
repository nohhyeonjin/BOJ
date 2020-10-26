//2:07
#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    char arr[9]={'C','A','M','B','R','I','D','G','E'};
    for(int i=0;i<s.size();i++){
        bool flag=false;
        for(int j=0;j<9;j++){
            if(s[i]==arr[j]){
                flag=true;
                break;
            }
        }
        if(!flag) cout << s[i];
    }
}