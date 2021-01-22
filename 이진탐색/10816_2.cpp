#include <bits/stdc++.h>
using namespace std;
int n,m;
int card[500000];
int have[500000];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&have[i]);
    sort(have,have+n);
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d",&card[i]);
        printf("%d ",upper_bound(have,have+n,card[i])-lower_bound(have,have+n,card[i]));
    }
}