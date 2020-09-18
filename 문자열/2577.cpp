#include <bits/stdc++.h>
using namespace std;
int a,b,c;
int arr[10];
int main(){
    scanf("%d %d %d",&a,&b,&c);
    int mul=a*b*c;
    string num=to_string(mul);
    for(int i=0;i<num.size();i++) arr[num[i]-'0']++;
    for(int i=0;i<10;i++) printf("%d\n",arr[i]);
}