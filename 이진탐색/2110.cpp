#include <bits/stdc++.h>
using namespace std;
int n,c,ans;
int house[200000];
void binary_search(int start, int end){
    while(start<=end){
        int prev=house[0];
        int cnt=1;
        int gap=(start+end)/2;
        for(int i=1;i<n;i++){
            if(house[i]-prev>=gap){
                cnt++;
                prev=house[i];
            }
        }
        if(cnt>=c){
            ans=max(ans,gap);
            start=gap+1;
        }else{
            end=gap-1;
        }
    }
}
int main(){
    scanf("%d %d",&n,&c);
    for(int i=0;i<n;i++) scanf("%d",&house[i]);
    sort(house,house+n);
    binary_search(1,house[n-1]-house[0]);
    printf("%d",ans);
}