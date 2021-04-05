#include <iostream>
using namespace std;
int cnt;
int minV=1000000;
int maxV=0;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> cnt;
    for(int i=0;i<cnt;i++){
        int num;
        cin >> num;
        if(minV>num) minV=num;
        if(maxV<num) maxV=num;
    }
    cout << minV*maxV;
}