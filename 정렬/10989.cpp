#include <bits/stdc++.h>
#define MAX 10001
using namespace std;
int cnt[MAX];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        cnt[num]++;
    } 
    for(int i=1;i<MAX;i++){
        for(int j=0;j<cnt[i];j++) printf("%d\n",i);
    }
}