#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int cost[1001][3];
int d[1001][3];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for(int i=1; i<=N; i++) cin >> cost[i][0] >> cost[i][1] >> cost[i][2];

    int ans = INT_MAX;
    for(int first=0; first<3; first++){
        for(int i=0; i<3; i++) d[2][i] = (i == first) ? INT_MAX : cost[2][i]+cost[1][first]; 

        for(int i=3; i<=N; i++){
            d[i][0] = min(d[i-1][1], d[i-1][2]) + cost[i][0];
            d[i][1] = min(d[i-1][0], d[i-1][2]) + cost[i][1];
            d[i][2] = min(d[i-1][0], d[i-1][1]) + cost[i][2];
        }

        for(int last = 0; last < 3; last++){
            if(first == last) continue;
            ans = min(ans, d[N][last]);
        }
    }

    cout << ans;
} 