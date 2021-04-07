#include <iostream>
#include <vector>
using namespace std;
int n;
vector<string> board;
int ans;
void count(int y, int x, int ny, int nx){
    for(int i=y;i<=ny;i++){
        int cnt=1;
        for(int j=1;j<n;j++){
            if(board[i][j]==board[i][j-1]) cnt+=1;
            else cnt=1;
            if(cnt>ans) ans=cnt;
        }
        
    }
    for(int i=x;i<=nx;i++){
        int cnt=1;
        for(int j=1;j<n;j++){
            if(board[j][i]==board[j-1][i]) cnt+=1;
            else cnt=1;
            if(cnt>ans) ans=cnt;
        }
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    board.resize(n);
    for(int i=0;i<n;i++){
        cin >> board[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i+1<n){  //아래
                swap(board[i][j],board[i+1][j]);
                count(i,j,i+1,j);
                swap(board[i][j],board[i+1][j]);
            }
            if(j+1<n){  //오른쪽
                swap(board[i][j],board[i][j+1]);
                count(i,j,i,j+1);
                swap(board[i][j],board[i][j+1]);
            }
        }
    }
    cout << ans;
}