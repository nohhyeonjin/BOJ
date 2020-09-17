#include <bits/stdc++.h>
using namespace std;
int m,n;
int arr[10001];
int main(){
    scanf("%d %d",&m,&n);
    arr[0]=arr[1]=0;
    for(int i=2;i<=n;i++) arr[i]=i;
    for(int i=2;i<=n;i++){
        if(arr[i]==0) continue;
        for(int j=i*2;j<=n;j+=i) arr[j]=0;
    }
    int cnt=0,sum=0;
    int minvalue=1e9;
    for(int i=m;i<=n;i++){
        if(arr[i]!=0){
            cnt++;
            sum+=i;
            minvalue=min(minvalue,i);
        }
    }
    if(cnt==0) printf("-1");
    else printf("%d\n%d",sum,minvalue);
}