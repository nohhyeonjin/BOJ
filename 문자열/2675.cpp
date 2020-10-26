#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int num;
        scanf("%d",&num);
        string s;
        cin >> s;
        for(int i=0;i<s.size();i++){
            for(int j=0;j<num;j++) cout << s[i];
        }
        printf("\n");
    }
}