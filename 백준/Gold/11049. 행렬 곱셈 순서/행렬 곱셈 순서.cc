#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

#define X first
#define Y second
int dp[501][501];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    pair<int, int> matrix[501];    
    for(int i=1; i<=N; i++) cin >> matrix[i].X >> matrix[i].Y;

    for(int len=2; len<=N; len++){
        for(int i=1; i<=N-len+1; i++){
            int j=i+len-1;
            dp[i][j] = INT_MAX;
            for(int k=i; k<j; k++){
                int cost = dp[i][k] + dp[k+1][j] + matrix[i].X*matrix[k].Y*matrix[j].Y; 
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    
    cout << dp[1][N];
} 