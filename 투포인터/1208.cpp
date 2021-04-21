#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,s;
long long ans;
vector<int> a;
int main(){
    scanf("%d %d",&n,&s);
    a.resize(n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    vector<int> leftSum, rightSum;
    int l=n/2;
    int r=n-n/2;
    //왼쪽 부분 수열
    for(int i=0;i<(1<<l);i++){
        int sum=0;
        for(int k=0;k<l;k++){
            if(i&(1<<k)) sum+=a[k];
        }
        leftSum.push_back(sum);
    }
    //오른쪽 부분 수열
    for(int i=0;i<(1<<r);i++){
        int sum=0;
        for(int k=0;k<r;k++){
            if(i&(1<<k)) sum+=a[n/2+k];
        }
        rightSum.push_back(sum);
    }
    sort(leftSum.begin(),leftSum.end());
    sort(rightSum.begin(),rightSum.end());
    reverse(rightSum.begin(),rightSum.end());
    int left=0,right=0;
    while(left<(1<<l)&&right<(1<<r)){
        if(leftSum[left]+rightSum[right]<s){
            left++;
        }else if(leftSum[left]+rightSum[right]==s){
            long long c1=1,c2=1;
            left++; right++;
            while(left<(1<<l)&&leftSum[left]==leftSum[left-1]){
                c1++; left++;
            }
            while(right<(1<<r)&&rightSum[right]==rightSum[right-1]){
                c2++; right++;
            }
            ans+=c1*c2;
        }else{
            right++;
        }
    }
    if(s==0) ans--;
    printf("%lld",ans);
}
