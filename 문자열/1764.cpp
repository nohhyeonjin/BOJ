#include <bits/stdc++.h>
using namespace std;
int n,m;
int cnt;
map<string, int> mp;
vector<string> answer;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n+m;i++){
        string s;
        cin >> s;
        if(mp.count(s)>0){
            mp[s]=mp[s]+1;
            cnt++;
            answer.push_back(s);
        }else mp[s]=1;
    }
    printf("%d\n",cnt);
    sort(answer.begin(),answer.end());
    for(int i=0;i<answer.size();i++) cout << answer[i] << "\n";
}