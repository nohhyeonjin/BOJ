#include <bits/stdc++.h>
using namespace std;
int n;
vector<string> numbers;
bool compare(string a, string b){
    if(a.size()!=b.size()) return a.size()<b.size();
    if(a.size()==b.size()){
        int aNum=0, bNum=0;
        for(int i=0;i<a.size();i++){
            if(isdigit(a[i])) aNum+=a[i]-'0';
            if(isdigit(b[i])) bNum+=b[i]-'0';
        }
        if(aNum!=bNum) return aNum<bNum;
        else return a<b;
    }
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        numbers.push_back(s);
    }
    sort(numbers.begin(),numbers.end(),compare);
    for(int i=0;i<n;i++) cout << numbers[i] << "\n";
}