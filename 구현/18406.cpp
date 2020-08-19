#include <bits/stdc++.h>
using namespace std;
int main(){
    char s[10];
    scanf("%s",s);
    int len=strlen(s);
    int l=0, r=0;
    for(int i=0;i<len/2;i++) l+=s[i]-'0';
    for(int i=len/2;i<len;i++) r+=s[i]-'0';
    if(l==r) printf("LUCKY");
    else printf("READY");
}