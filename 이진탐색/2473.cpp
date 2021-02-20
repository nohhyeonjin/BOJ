#include <bits/stdc++.h>
using namespace std;
int n;
long long liq[5000];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%lld",&liq[i]);
    sort(liq,liq+n);
    long long minValue=LLONG_MAX;
    int resultIdx[3];
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            long long ij=liq[i]+liq[j];
            int idx=lower_bound(liq,liq+n,-ij)-liq;
            for(int k=idx-5;k<idx+5;k++){
                if(k<0||k>=n||k==i||k==j) continue;
                long long sum=ij+liq[k];
                if(abs(sum)<minValue){
                    minValue=abs(sum);
                    resultIdx[0]=i;
                    resultIdx[1]=j;
                    resultIdx[2]=k;
                }
            }
        }
    }
    sort(resultIdx,resultIdx+3);
    for(int i=0;i<3;i++) printf("%lld ",liq[resultIdx[i]]);
}