#include <iostream>

long long p[101];
int main(){
    int t,n;
    scanf("%d",&t);
    p[1]=p[2]=p[3]=1;
    p[4]=p[5]=2;
    for(int i=0;i<t;i++){
        scanf("%d",&n);
        for(int j=6;j<=n;j++){
            p[j]=p[j-1]+p[j-5];
        }
        printf("%lld\n",p[n]);
    }
}