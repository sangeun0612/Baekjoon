#include <iostream>
#include <algorithm>
using namespace std;

int d[1001][1001];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size(), m = s2.size();

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s1[i-1] == s2[j-1]) d[i][j] = d[i-1][j-1]+1;
            else d[i][j] = max(d[i-1][j], d[i][j-1]);
            
        }
    }

    cout << d[n][m] << "\n";

    string ans = "";
    int i = n, j = m;
    while(i>0 && j>0){
        if(s1[i-1] == s2[j-1]){
            ans += s1[i-1];
            i--, j--;
        }
        else if(d[i-1][j] > d[i][j-1]) i--;
        else j--;
    } 

    reverse(ans.begin(), ans.end());
    cout << ans;
} 