#include <bits/stdc++.h>
using namespace std;
int main(){
    int h,w;
    scanf("%d %d",&h,&w);
    if(h==1) printf("1");
    if(h==2) printf("%d",min(4,(w+1)/2));
    if(h>=3){
        if(w>6) printf("%d",w-2);
        else printf("%d",min(4,w));
    }
}