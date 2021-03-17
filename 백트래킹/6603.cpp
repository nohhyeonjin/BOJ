#include <iostream>
using namespace std;
int t;
int arr[13];
bool selected[13];
void dfs(int idx, int cnt){
    if(cnt==6){
        for(int i=0;i<t;i++) if(selected[i]) cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for(int i=idx;i<t;i++){
        if(selected[i]) continue;
        selected[i]=true;
        dfs(i+1,cnt+1);
        selected[i]=false;
    }
}
int main(){
    while(1){
        cin >> t;
        if(t==0) break;
        for(int i=0;i<t;i++) cin >> arr[i];
        dfs(0,0);
        cout << "\n";
    }
}