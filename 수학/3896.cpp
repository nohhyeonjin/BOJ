#include <bits/stdc++.h>
#define MAX 1299710
using namespace std;
bool prime[MAX];
int main(){
    int t;
    scanf("%d",&t);
    //에라토스테네스의 체
    fill(prime+2,prime+MAX,true);
    for(int i=2;i<MAX;i++){
        for(int j=i*2;j<MAX;j+=i){
            if(prime[j]!=false) prime[j]=false;
        }
    }
    while(t--){
        int num;
        scanf("%d",&num);
        int idx=num;
        int ans=0;
        while(1){
            if(prime[idx]==true) break;
            idx--;
            ans++;
        }
        idx=num;
        while(1){
            if(prime[idx]==true) break;
            idx++;
            ans++;
        }
        printf("%d\n",ans);
    }
}