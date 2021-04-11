#include <iostream>
#define MOD 9901
using namespace std;
int n;
int d[100001][3];
int main(){
    cin >> n;
    for(int i=0;i<3;i++) d[1][i]=1;
    for(int i=2;i<=n;i++){
        d[i][0]=(d[i-1][0]+d[i-1][1]+d[i-1][2])%MOD;
        d[i][1]=(d[i-1][0]+d[i-1][2])%MOD;
        d[i][2]=(d[i-1][0]+d[i-1][1])%MOD;
    }
    int ans=0;
    for(int i=0;i<3;i++) ans=(ans+d[n][i])%MOD;
    cout << ans;
}