#include <iostream>
#include <algorithm>
using namespace std;
int n,ans;
int arr[8];
int result[8];
bool selected[8];
void dfs(int cnt){
    if(cnt==n){
        int sum=0;
        for(int i=0;i<n-1;i++){
            int a=result[i];
            int b=result[i+1];
            sum+=abs(a-b);
        }
        ans=max(ans,sum);
    }
    for(int i=0;i<n;i++){
        if(selected[i]) continue;
        selected[i]=true;
        result[cnt]=arr[i];
        dfs(cnt+1);
        selected[i]=false;
    }
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];
    dfs(0);
    cout << ans;
}