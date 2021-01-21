#include <bits/stdc++.h>
using namespace std;
int n;
char node[26][2];
void preorder(char cur){
    if(cur=='.') return;
    cout << cur;
    preorder(node[cur-'A'][0]);
    preorder(node[cur-'A'][1]); 
}
void inorder(char cur){
    if(cur=='.') return;
    inorder(node[cur-'A'][0]);
    cout << cur;
    inorder(node[cur-'A'][1]);
}
void postorder(char cur){
    if(cur=='.') return;
    postorder(node[cur-'A'][0]);
    postorder(node[cur-'A'][1]);
    cout << cur;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++){
        char root, left, right;
        cin >> root >> left >> right;
        node[root-'A'][0]=left;
        node[root-'A'][1]=right;
    }
    preorder('A');
    cout << endl;
    inorder('A');
    cout << endl;
    postorder('A');
}