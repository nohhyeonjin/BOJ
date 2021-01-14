#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    stack<int> s;
    for(int i=0;i<n;i++){
        string order;
        cin >> order;
        if(order=="push"){
            int num;
            cin >> num;
            s.push(num);
        }
        if(order=="top"){
            if(s.empty()) cout << "-1" << "\n";
            else cout << s.top() << "\n";
        }
        if(order=="size"){
            cout << s.size() << "\n";
        }
        if(order=="pop"){
            if(s.empty()) cout << "-1" << "\n";
            else{
                cout << s.top() << "\n";
                s.pop();
            }
        }
        if(order=="empty"){
            if(s.empty()) cout << "1" << "\n";
            else cout << "0" << "\n";
        }
    }
}