#include <iostream>
#include <vector>
#include <map>
#define MAX 10001
#define INF 1e9
using namespace std;
int t,n;
bool arr[MAX];
int main(){
    for(int i=2;i*i<MAX;i++){
        if(arr[i]) continue;
        for(int j=i*2;j<MAX;j+=i) arr[j]=true;
    }
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=n/2;i>=2;i--){
            if(!arr[i]&&!arr[n-i]){
                printf("%d %d\n",i,n-i);
                break;
            }
        }
    }
}