#include <bits/stdc++.h>
using namespace std;
char s[100000];
int main(){
    int sum=0;
    scanf("%s",s);
    vector<int> v;
    int len=strlen(s);
    for(int i=0;i<len;i++){
        v.push_back(s[i]-'0');
        sum+=s[i]-'0';
    }
    sort(v.begin(),v.end(),greater<int>());
    if(v[v.size()-1]==0&&sum%3==0){ //3의 배수는 각 자리의 합이 3의 배수여야함
        for(int i=0;i<v.size();i++) printf("%d",v[i]);
    }else{
        printf("-1");
    }
}