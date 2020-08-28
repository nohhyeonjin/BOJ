#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    priority_queue<int,vector<int>,greater<int>> card;
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        card.push(num);
    }
    int ans=0;
    if(n>1){
        while(1){
            int sum=0;
            for(int i=0;i<2;i++){
                int num=card.top();
                card.pop();
                sum+=num;
                ans+=num;
            }
            if(card.empty()) break;
            card.push(sum);
        }
    }
    printf("%d",ans);
}