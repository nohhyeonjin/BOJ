#include <bits/stdc++.h>
#define SIZE 100000
using namespace std;
int main(){
    int a[SIZE],b[SIZE];
    for(int i=0;i<SIZE;i++) scanf("%1d",&a[i]);
    for(int i=0;i<SIZE;i++) scanf("%1d",&b[i]);
    
    for(int i=0;i<SIZE;i++) printf("%d",a[i]&b[i]);
    printf("\n");
    for(int i=0;i<SIZE;i++) printf("%d",a[i]|b[i]);
    printf("\n");
    for(int i=0;i<SIZE;i++) printf("%d",a[i]^b[i]);
    printf("\n");
    for(int i=0;i<SIZE;i++) printf("%d",!a[i]);
    printf("\n");
    for(int i=0;i<SIZE;i++) printf("%d",!b[i]);
    printf("\n");
}