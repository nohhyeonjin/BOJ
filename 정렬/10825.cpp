#include <bits/stdc++.h>
using namespace std;
class student{
public:
    string name;
    int kor;
    int eng;
    int math;
    student(string name, int kor, int eng, int math){
        this->name=name;
        this->kor=kor;
        this->eng=eng;
        this->math=math;
    }
    bool operator <(student& other){
        if(kor==other.kor&&eng==other.eng&&math==other.math) return name<other.name;
        if(kor==other.kor&&eng==other.eng) return math>other.math;
        if(kor==other.kor) return eng<other.eng;
        if(kor!=other.kor) return kor>other.kor;
    }
};
vector<student> v;
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string name;
        int kor, eng, math;
        cin >> name >> kor >> eng >> math;
        v.push_back(student(name,kor,eng,math));
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++) cout << v[i].name << '\n';
}