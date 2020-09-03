#include <bits/stdc++.h>
using namespace std;
int n;
class member{
    public:
        int age;
        string name;
        int order;
        member(int age, string name, int order){
            this->age=age;
            this->name=name;
            this->order=order;
        }
        bool operator <(member& other){
            if(age==other.age) return order<other.order;
            return age<other.age;
        }
};
vector<member> m;
int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    cin >> n;
    int order=0;
    for(int i=0;i<n;i++){
        string name;
        int age;
        cin >> age >> name;
        order++;
        m.push_back(member(age,name,order));
    }
    sort(m.begin(),m.end());
    for(int i=0;i<n;i++) cout << m[i].age << " " << m[i].name << "\n";
}