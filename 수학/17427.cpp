#include <iostream>
using namespace std;
int n;
long long ans;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++) ans+=n/i*i;
    cout << ans;
}