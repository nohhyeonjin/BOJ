#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        vector<int> v;
        v.resize(n+1);
        for(int i=0;i<n;i++){
            int a,b;
            scanf("%d %d",&a,&b);
            v[a]=b;
        }
        int ans=1;
        int minVal = v[1];
        for(int i=2;i<=n;i++){
            if(v[i]<minVal){
                ans++;
                minVal=v[i];
            }
        }
        printf("%d\n",ans);       
    }
}