#include <bits/stdc++.h>
using namespace std;
int t;
int main(){
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        bool isP;       
        for(int i=2;i<=64;i++){
            int num=n;
            isP=false;
            vector<int> v;
            while(1){
                v.push_back(num%i);
                num=num/i;
                if(num==0) break;
            }
            bool chk=true;
            for(int j=v.size()-1;j>=0;j--){
                if(v[j]!=v[v.size()-1-j]) chk=false;
            }
            if(chk==true){
                isP=true;
                break;
            }
            else isP=false;
        }
        if(isP==false) printf("0\n");
        else printf("1\n");
    }
}