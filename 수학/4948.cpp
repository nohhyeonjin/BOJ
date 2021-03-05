#include <iostream>
#define MAX 250000
using namespace std;
int n;
bool arr[MAX];
int main(){
    for(int i=2;i*i<MAX;i++){
        if(arr[i]) continue;
        for(int j=i*2;j<MAX;j+=i) arr[j]=true;
    }
    while(1){
        int ans=0;
        scanf("%d",&n);
        if(n==0) break;
        for(int i=n+1;i<=2*n;i++) if(!arr[i]) ans++;
        printf("%d\n",ans);
    }
}