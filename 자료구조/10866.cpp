#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    deque<int> dq;
    for(int i=0;i<n;i++){
        string order;
        cin >> order;
        if(order=="push_front"){
            int num;
            cin >> num;
            dq.push_front(num);
        }
        if(order=="push_back"){
            int num;
            cin >> num;
            dq.push_back(num);
        }
        if(order=="pop_front"){
            if(dq.empty()) cout << "-1" << "\n";
            else{
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        }
        if(order=="pop_back"){
            if(dq.empty()) cout << "-1" << "\n";
            else{
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        }
        if(order=="size") cout << dq.size() << "\n";
        if(order=="empty") cout << (dq.empty()?1:0) << "\n";
        if(order=="front"){
            if(dq.empty()) cout << "-1" << "\n";
            else{
                cout << dq.front() << "\n";
            }
        }
        if(order=="back"){
            if(dq.empty()) cout << "-1" << "\n";
            else{
                cout << dq.back() << "\n";
            }
        }
    }
}