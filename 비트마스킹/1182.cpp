#include <iostream>
using namespace std;
int n,s;
int arr[20];
int ans;
int main(){
    scanf("%d %d",&n,&s);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    for(int i=1;i<(1<<n);i++){
        int sum=0;
        for(int j=0;j<n;j++){
            if(i&(1<<j)) sum+=arr[j]; 
        }
        if(sum==s) ans++;
    }
    printf("%d",ans);
}