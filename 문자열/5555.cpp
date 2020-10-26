#include <bits/stdc++.h>
using namespace std;
int main(){
    string want;
    cin >> want;
    int n, ans=0;
    scanf("%d",&n);
    while(n--){
        string s;
        cin >> s;
        for(int i=0;i<s.size()+want.size();i++){
            int j=i;
            bool flag=true;
            for(int k=0;k<want.size();k++){
                if(j>=s.size()) j=j-s.size();
                if(s[j++]!=want[k]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                ans++;
                break;
            }
        }
    }
    printf("%d",ans);
}