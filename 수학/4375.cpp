#include <iostream>
using namespace std;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    while(cin >> n){
        int num=0;
        for(int i=1;;i++){
            num=(num*10+1)%n;
            if(num==0){
                cout << i << '\n';
                break;
            }
        }
    }
}