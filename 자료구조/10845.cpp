#include <bits/stdc++.h>
using namespace std;
int main(){
    queue<int> q;
    int t;
    scanf("%d",&t);
    getchar();
    while(t--){
        string s;
        getline(cin,s);
        stringstream ss(s);
        string order;
        int num;
        ss >> order >> num;
        if(order=="push") q.push(num);
        if(order=="pop"){
            if(q.empty()) printf("-1\n");
            else{
                printf("%d\n",q.front());
                q.pop();
            }
        }
        if(order=="size") printf("%d\n",q.size());
        if(order=="empty") (q.empty()?printf("1\n"):printf("0\n"));
        if(order=="front"){
            if(q.empty()) printf("-1\n");
            else printf("%d\n",q.front());
        }
        if(order=="back"){
            if(q.empty()) printf("-1\n");
            else printf("%d\n",q.back());
        }
    }
}