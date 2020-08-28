#include <bits/stdc++.h>
#define MIN(x,y) (x<y?x:y)
using namespace std;
vector<pair<int,int>> chicken,house;
vector<vector<int>> chDis;
int n,m;
void input(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int num;
            scanf("%d",&num);
            if(num==1) house.push_back(make_pair(i,j));
            if(num==2) chicken.push_back(make_pair(i,j));
        }
    }
}
void cal_dis(){
    for(int i=0;i<chicken.size();i++){
        vector<int> disList;
        for(int j=0;j<house.size();j++){
            int dis=abs(chicken[i].first-house[j].first)+abs(chicken[i].second-house[j].second);
            disList.push_back(dis);
        }
        chDis.push_back(disList);
    }
}
int get_minDis(){
   //조합
   vector<int> idx(chicken.size());
   fill(idx.end()-m,idx.end(),1);
   int ans=987654321;
   do{
       vector<vector<int>> select;
       for(int i=0;i<chicken.size();i++) if(idx[i]==1) select.push_back(chDis[i]);
       int sum=0;
       for(int i=0;i<house.size();i++){
           int min=987654321;
           for(int j=0;j<select.size();j++){
               min=MIN(min,select[j][i]);
           }
           sum+=min;
       }
       ans=MIN(ans,sum);
    }while(next_permutation(idx.begin(),idx.end()));
    return ans;
}
int main(){
    input();
    cal_dis();
    printf("%d",get_minDis());
}