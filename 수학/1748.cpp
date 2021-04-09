#include <iostream>
#include <cmath>
#include <string>
using namespace std;
string n;
long long ans;
int main(){
    cin >> n;
    int len = n.size();
    for(int i=1;i<len;i++) ans+=i*9*pow(10,i-1);
    ans+=len*(stoi(n)-pow(10,len-1)+1);
    cout << ans;
}