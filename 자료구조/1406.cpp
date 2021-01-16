#include <bits/stdc++.h>
using namespace std;
int main(){
    char str[100001];
    scanf("%s",&str);
    getchar();
    int m;
    scanf("%d",&m);
    getchar();
    list<char> lst;
    for(int i=0;str[i]!='\0';i++) lst.push_back(str[i]);
    list<char>::iterator iter=lst.end();
    for(int i=0;i<m;i++){
        char order;
        scanf("%c",&order);
        getchar();
        if(order=='L'){
            if(iter!=lst.begin()) iter--;
        }
        if(order=='D'){
            if(iter!=lst.end()) iter++;
        }
        if(order=='B'){
            if(iter!=lst.begin()){
                iter--;
                iter=lst.erase(iter);
            }
        }
        if(order=='P'){
            char c;
            scanf(" %c",&c);
            getchar();
            lst.insert(iter,c);
        }
    }
    for(iter=lst.begin();iter!=lst.end();iter++) printf("%c",*iter);
}