#include <iostream>
using namespace std;
int m;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> m;
    int s=0;
    while(m--){
        string order;
        int x;
        cin >> order;
        if(order=="add"){
            cin >> x;
            s=s|(1<<x);            
        }
        if(order=="remove"){
            cin >> x;
            s=s&~(1<<x);
        }
        if(order=="check"){
            cin >> x;
            if(s&(1<<x)) cout << "1" << "\n";
            else cout << "0" << "\n";
        }
        if(order=="toggle"){
            cin >> x;
            s=s^(1<<x);
        }
        if(order=="all"){
            s=(1<<21)-1;
        }
        if(order=="empty"){
            s=0;
        }
    }
}