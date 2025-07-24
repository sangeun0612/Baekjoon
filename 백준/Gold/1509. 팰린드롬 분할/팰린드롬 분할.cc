#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

bool isPalindrome[2501][2501];
int d[2501];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string S;
    cin >> S;

    for(int i=1; i <= S.size(); i++) {
        isPalindrome[i][i] = true;  //길이가 1일 때
        if(i < S.size() && S[i-1] == S[i]) isPalindrome[i][i+1] = true;  //길이가 2일 때
    }

    for(int len = 2; len < S.size(); len++){
        for(int i = 1; i <= S.size()-len; i++){
            int j = i+len;
            if(S[i-1] == S[j-1] && isPalindrome[i+1][j-1]) isPalindrome[i][j] = true;
        }
    }  

    for(int i=1; i <= S.size(); i++){
        d[i] = INT_MAX;
        for(int j=1; j<=i; j++){
            if(isPalindrome[j][i]) d[i] = min(d[i], d[j-1] + 1);
        }
    }
    
    cout << d[S.size()];
} 