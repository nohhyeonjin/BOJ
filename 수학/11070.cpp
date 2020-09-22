#include <bits/stdc++.h>
using namespace std;
int t;
int arr[2][1001];   //arr[0][x] : 득 / arr[1][x] : 실
int main(){
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        double small=1e9, big=0;
        for(int i=0;i<2;i++) memset(arr[i],0,sizeof(int)*1001);
        for(int i=0;i<m;i++){
            int a,b,p,q;
            scanf("%d %d %d %d",&a,&b,&p,&q);
            arr[0][a]+=p; arr[1][b]+=p;
            arr[1][a]+=q; arr[0][b]+=q;
        }
        for(int i=1;i<=n;i++){
            int s=arr[0][i];
            int a=arr[1][i];
            double w;
            if(s==0&&a==0) w=0;
            else w=(double)(s*s)/(double)(s*s+a*a)*1000;
            small=min(small,w);
            big=max(big,w);
        }
        cout << (int)big << "\n" << (int)small << "\n";
    }
}