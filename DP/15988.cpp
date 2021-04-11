#include <iostream>
#define MOD 1000000009
#define MAX 1000000
using namespace std;
int t;
int d[MAX+1];
int main(){
    d[0]=d[1]=1; d[2]=2;
    for(int i=3;i<=MAX;i++){
        d[i]=(d[i]+d[i-1])%MOD;
        d[i]=(d[i]+d[i-2])%MOD;
        d[i]=(d[i]+d[i-3])%MOD;
    }
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << d[n] << '\n';
    }
}