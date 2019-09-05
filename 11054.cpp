#include <iostream>

int num[1001], ltr[1001], rtl[1001];
int main(){
    int n,max,ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&num[i]);
    ltr[1]=rtl[n]=1;
    for(int i=2;i<=n;i++){
        max=0;
        for(int j=1;j<=i-1;j++){
            if(num[j]<num[i]&&max<ltr[j]) max=ltr[j];
        }
        ltr[i]=max+1;
    }
    for(int i=n-1;i>=1;i--){
        max=0;
        for(int j=n;j>=i-1;j--){
            if(num[j]<num[i]&&max<rtl[j]) max=rtl[j];
        }
        rtl[i]=max+1;
    }
    for(int i=1;i<=n;i++){
        if(ans<ltr[i]+rtl[i]) ans=ltr[i]+rtl[i];
    }
    printf("%d\n",ans-1);
}