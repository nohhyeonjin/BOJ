#include <bits/stdc++.h>
using namespace std;
int ans;
int main(){
    int n;
    scanf("%d",&n);
    string want;
    cin >> want;
    while(n--){
        string s;
        cin >> s;
        vector<int> pos[2];
        for(int i=0;i<s.size();i++){
            for(int j=0;j<2;j++) if(s[i]==want[j]) pos[j].push_back(i);
        }
        for(int i=0;i<pos[0].size();i++){
            int firstPos=pos[0][i];
            bool flag=false;
            for(int j=0;j<pos[1].size();j++){
                int secondPos=pos[1][j];
                if(firstPos>secondPos) continue;
                int dis=secondPos-firstPos;
                int pos=secondPos+dis;
                int cnt=0;
                for(int k=2;k<want.size();k++,pos+=dis){
                    if(pos>s.size()-1) break;
                    if(want[k]==s[pos]) cnt++;
                }
                if(cnt==want.size()-2){
                    ans++;
                    flag=true;
                    break;
                }
            }
            if(flag) break;
        }
    }
    printf("%d",ans);
}