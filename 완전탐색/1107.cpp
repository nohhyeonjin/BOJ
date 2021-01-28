#include <bits/stdc++.h>
using namespace std;
int n,m;
bool num[10]; 
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    memset(num,1,sizeof(num));
    for(int i=0;i<m;i++){
        int a;
        cin >> a;
        num[a]=false;
    }
    int ans=abs(n-100);
    for(int i=0;i<=888888;i++){
        string tmp=to_string(i);
        bool flag=true;
        for(int j=0;j<tmp.size();j++){
            if(num[tmp[j]-'0']==0){
                flag=false;
                break;
            }
        }
        if(flag){
            ans=min(ans,(int)(abs(n-stoi(tmp))+tmp.size()));
        }
    }
    cout << ans;
}