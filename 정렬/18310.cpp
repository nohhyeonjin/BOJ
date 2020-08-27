#include <bits/stdc++.h>
using namespace std;
vector<int> house;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        house.push_back(num);
    }
    sort(house.begin(),house.end());
    printf("%d",house[(n-1)/2]);
}