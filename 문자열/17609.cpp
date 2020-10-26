#include <bits/stdc++.h>
using namespace std;
int chk_palindrome(int start, int end, string s, int cnt){
    for(;start<=end;start++,end--){
        if(s[start]!=s[end]){
            if(cnt==0){    
                int left=chk_palindrome(start+1,end,s,cnt+1);
                int right=chk_palindrome(start,end-1,s,cnt+1);
                if(left==0||right==0) return 1;
            }
            return 2;
        }
    }
    return 0;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        string s;
        cin >> s;
        printf("%d\n", chk_palindrome(0,s.size()-1,s,0));
    }
}