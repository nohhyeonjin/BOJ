#include <bits/stdc++.h>
using namespace std;
long long n,w,coin;
int arr[17];
int main(){
    scanf("%d %d",&n,&w);
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
    //올라갈때 사고 내려갈때 팔기
    bool up=false;
    for(int i=1;i<=n;i++){
        int cur=arr[i];
        int next=arr[i+1];
        if(cur<next&&up==false){    //내려가던중이었고 현재 올라갔다면 매수
            coin=coin+w/cur;
            w=w%cur;
            up=true;
        }
        if((cur>next&&up==true)||(i==n)){     //올라가던중이었고 현재 내려갔다면 매도
            w=w+coin*cur;
            coin=0;
            up=false;
        }
    }
    printf("%lld",w);
}