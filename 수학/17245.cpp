#include <iostream>
using namespace std;
const int MAX = 1000000;
long long d[MAX+1], sum[MAX+1];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    for(int i=1;i<=MAX;i++){
        for(int j=1;j*i<=MAX;j++){
            d[i*j]+=i;
        }
    }
    for(int i=1;i<=MAX;i++) sum[i]=sum[i-1]+d[i];
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << sum[n] << "\n";
    }
}