#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,ans=0;
        scanf("%d %d",&n,&m);
        map<int,int> mp;    //문서번호, 중요도
        queue<int> q; //문서번호
        int maxP=0;
        for(int i=0;i<n;i++){
            int num;
            scanf("%d",&num);
            mp.insert({i,num});
            q.push(i);
            maxP=max(maxP,num);
        }
        while(1){
            int num=q.front();
            int pri=mp[num];
            q.pop();
            if(pri<maxP) q.push(num);
            else{
                ans++;
                if(num==m) break;
                mp.erase(num);
                map<int,int>::iterator iter;
                maxP=0;
                for(iter=mp.begin();iter!=mp.end();iter++) maxP=max(maxP,iter->second);
            }
        }
        printf("%d\n",ans);
    }    
}