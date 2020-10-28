#include <bits/stdc++.h>
using namespace std;
int ans;
int main(){
    int n,p;
    scanf("%d %d",&n,&p);
    stack<int> s[7];
    for(int i=0;i<n;i++){
        int line, pr;
        scanf("%d %d",&line,&pr);
        while(1){
            if(s[line].empty()){
                s[line].push(pr);
                ans++;
                break;
            }
            if(s[line].top()==pr) break;
            if(s[line].top()<pr){
                s[line].push(pr);
                ans++;
                break;
            }
            s[line].pop();
            ans++;
        }
    }
    printf("%d",ans);
}