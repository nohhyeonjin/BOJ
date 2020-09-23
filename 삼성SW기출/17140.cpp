#include <bits/stdc++.h>
using namespace std;
int r,c,k;
vector<vector<int>> arr;
void input(){
    scanf("%d %d %d",&r,&c,&k);
    for(int i=0;i<3;i++){
        vector<int> row;
        for(int j=0;j<3;j++){
            int num;
            scanf("%d",&num);
            row.push_back(num);
        }
        arr.push_back(row);
    }
}
bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second==b.second) return a.first<b.first;
    return a.second<b.second;
}
vector<pair<int,int>> mapSort(map<int,int> m){    
    vector<pair<int,int>> v(m.begin(),m.end());
    sort(v.begin(),v.end(),cmp);
    return v;
}
void oper(char type){
    int rSize=arr.size();
    int cSize=arr[0].size();
    if(type=='C') swap(rSize,cSize);
    int maxSize=0;
    vector<vector<int>> v;
    for(int r=0;r<rSize;r++){
        map<int,int> m;
        //숫자 개수 카운트
        for(int c=0;c<cSize;c++){
            int num;
            if(type=='R') num=arr[r][c];
            if(type=='C') num=arr[c][r];
            if(num==0) continue;
            //키 값으로 num이 존재하지않으면
            if(m.count(num)==0) m.insert({num,1});
            else m[num]=m[num]+1;
        }
        //map value기준 오름차순 정렬
        vector<pair<int,int>> sortedMap=mapSort(m);
        maxSize=max(maxSize,(int)sortedMap.size()*2);
        vector<int> row;
        for(int i=0;i<sortedMap.size();i++){
            if(i==50) break;
            int key=sortedMap[i].first, value=sortedMap[i].second;
            row.push_back(key);
            row.push_back(value);
        }
        v.push_back(row);
    }
    //0붙이기
    for(int i=0;i<v.size();i++){
        int cnt=maxSize-v[i].size();
        for(int j=0;j<cnt;j++) v[i].push_back(0);
    }
    arr=v;
    //전치행렬
    if(type=='C'){
        vector<vector<int>> v;
        for(int i=0;i<arr[0].size();i++){
            vector<int> row;
            for(int j=0;j<arr.size();j++) row.push_back(arr[j][i]);
            v.push_back(row);
        }
        arr=v;
    }
}
int solution(){
    int cnt=0;
    while(1){
        int rSize=arr.size(), cSize=arr[0].size();
        if(rSize>=r&&cSize>=c){
            if(arr[r-1][c-1]==k) return cnt;
        }
        if(cnt>100) return -1;
        cnt++;
        if(rSize>=cSize) oper('R');
        else oper('C');
    }
}
int main(){
    input();
    printf("%d",solution());
}