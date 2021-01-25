#include <bits/stdc++.h>
using namespace std;
int n;
stack<int> st[4];
vector<pair<int,int>> ans;
void move(int firstPos, int secondPos){
    int first=st[firstPos].top();
    st[firstPos].pop();
    st[secondPos].push(first);
    ans.push_back({firstPos,secondPos});
}
void hanoi(int num, int from, int to, int rest){
    if(num==1){
        move(from,to);
        return;
    }
    hanoi(num-1,from,rest,to);
    move(from,to);
    hanoi(num-1,rest,to,from);
}
int main(){
    scanf("%d",&n);
    for(int i=n;i>0;i--) st[1].push(i);
    hanoi(n,1,3,2);
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].first,ans[i].second);
}