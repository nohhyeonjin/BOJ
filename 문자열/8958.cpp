#include <bits/stdc++.h>
using namespace std;
int t;
int main(){
    scanf("%d",&t);
    while(t--){
        string s;
        cin >> s;
        int cnt=0, ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='O'){
                cnt++;
                ans+=cnt;
            }
            if(s[i]=='X'){
                cnt=0;
            }
        }
        printf("%d\n",ans);
    }
}