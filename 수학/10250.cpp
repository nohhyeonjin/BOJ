#include <bits/stdc++.h>
using namespace std;
int t;
int main(){
    scanf("%d",&t);
    while(t--){
        int h,w,n;
        scanf("%d %d %d",&h,&w,&n);
        int floor,number;
        bool find=false;
        int cnt=0;
        for(int i=1;i<=w;i++){
            for(int j=1;j<=h;j++){
                cnt++;
                if(cnt==n){
                    floor=j;
                    number=i;
                    find=true;
                    break;
                } 
            }
            if(find==true) break;
        }
        string s;
        s+=to_string(floor);
        if(number<10) s+='0';
        s+=to_string(number);
        cout << s << "\n";
    }
}