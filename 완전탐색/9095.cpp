#include <iostream>
using namespace std;
int cnt[4];
int n;
int go(int sum){
    if(sum==n) return 1;
    if(sum>n) return 0;
    int now=0;
    for(int i=1;i<=3;i++){
        cnt[i]++;
        now+=go(sum+i);
        cnt[i]--;
    }
    return now;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        cout << go(0) << '\n';
    }
}