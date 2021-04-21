#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int t,n,m;
long long ans;
int a[1000],b[1000];
vector<long long> aSum, bSum;
int main(){
    scanf("%d",&t);
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    scanf("%d",&m);
    for(int i=0;i<m;i++) scanf("%d",&b[i]);
    //A부배열 합
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=a[j];
            aSum.push_back(sum);
        }
    }
    //B부배열 합
    for(int i=0;i<m;i++){
        int sum=0;
        for(int j=i;j<m;j++){
            sum+=b[j];
            bSum.push_back(sum);
        }
    }
    sort(aSum.begin(),aSum.end());
    sort(bSum.begin(),bSum.end());
    for(int i=0;i<aSum.size();i++){
        long long x=t-aSum[i];
        auto cnt=equal_range(bSum.begin(),bSum.end(),x);
        ans+=(cnt.second-cnt.first);
    }
    printf("%lld",ans);
}