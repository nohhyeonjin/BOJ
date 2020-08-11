#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,m;
    vector<int> v;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n+m;i++) {
        int num;
        scanf("%d",&num);
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++) printf("%d ",v[i]);
}