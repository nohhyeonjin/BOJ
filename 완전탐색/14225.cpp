#include <iostream>
#include <algorithm>
using namespace std;
int s;
int a[20];
int prevV;
int maxV;
bool flag;
void go(int idx, int sum){
    if(idx==s){
        if(sum-prevV>=2){
            flag=true;
            printf("%d",prevV+1);
            exit(0);
        }
        prevV=sum;
        return;
    }
    go(idx+1,sum);
    go(idx+1,sum+a[idx]);
}
int main(){
    scanf("%d",&s);
    for(int i=0;i<s;i++){
        scanf("%d",&a[i]);
        maxV+=a[i];
    }
    sort(a,a+s,greater<>());
    go(0,0);
    if(!flag) printf("%d",maxV+1);
}