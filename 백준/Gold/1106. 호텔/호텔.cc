#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int d[1101][21];
int cost[21], num[21];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int C, N;
    cin >> C >> N;
    for(int i=1; i<=N; i++) cin >> cost[i] >> num[i];
    for(int i=1; i<=C+100; i++) fill(d[i], d[i]+N+1, 2001);

    for(int i=1; i<=C+100; i++) {
        for(int j=1; j<=N; j++){
            if(i-num[j] >= 0) d[i][j] = *min_element(d[i-num[j]]+1, d[i-num[j]]+N+1) + cost[j];
            //cout << "d[" << i << "][" << j << "]: " << d[i][j] << " ";
        }
        //cout << "\n";
    }

    int ans = INT_MAX;
    for(int i=0; i<100; i++) {
        ans = min(ans, *min_element(d[C+i]+1, d[C+i]+N+1));
        //cout << "d[" << C+i << "][1]: " << ans << "\n";
    }
    cout << ans;
} 