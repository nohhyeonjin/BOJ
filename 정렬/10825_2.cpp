#include <bits/stdc++.h>
using namespace std;
class student{
public:
    string name;
    int a,b,c;
    student(string name,int a,int b,int c){
        this->name=name;
        this->a=a;
        this->b=b;
        this->c=c;
    }
};
bool compare(student a, student b){
    if(a.a==b.a&&a.b==b.b&&a.c==b.c) return a.name<b.name;
    if(a.a==b.a&&a.b==b.b) return a.c>b.c;
    if(a.a==b.a) return a.b<b.b;
    return a.a>b.a;
    
}
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<student> v;
    for(int i=0;i<n;i++){
        string name;
        int a,b,c;
        cin >> name >> a >> b >> c;
        v.push_back(student(name,a,b,c));
    }
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<n;i++) cout << v[i].name << "\n";
}