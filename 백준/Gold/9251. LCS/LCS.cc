#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int d[1001][1001];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i-1] == b[j-1]) d[i][j] = d[i-1][j-1] +1;
            d[i][j] = max({d[i][j], d[i-1][j], d[i][j-1]});
        }
    }
    cout << d[n][m];
} 