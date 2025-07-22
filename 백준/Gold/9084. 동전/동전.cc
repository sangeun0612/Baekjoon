#include <iostream>
#include <algorithm>
using namespace std;

int t, n, m;
int coin[21];
int d[21][10'001];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> coin[i];
            d[i][0] = 1;
        }
        cin >> m;
        for(int i=0; i<n; i++){
            for(int j=1; j<=m; j++){
                d[i][j] = 0;
                if(i-1 >= 0) d[i][j] += d[i-1][j];
                if(j-coin[i] >= 0) d[i][j] += d[i][j-coin[i]];
            }
        }
        cout << d[n-1][m] << "\n";
    }
    
} 