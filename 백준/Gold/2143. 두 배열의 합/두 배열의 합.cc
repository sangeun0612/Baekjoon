#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a1[1'001], a2[1'001];
int dp1[1'001], dp2[1'001];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> a1[i];
        dp1[i] = a1[i] + dp1[i-1]; 
    }

    int m;
    cin >> m;
    for(int i=1; i<=m; i++) {
        cin >> a2[i];
        dp2[i] = a2[i] + dp2[i-1];
    }

    vector<int> v1;
    for(int i=1; i<=n; i++)
        for(int j=0; j<i; j++)
            v1.push_back(dp1[i]-dp1[j]);

    vector<int> v2;
    for(int i=1; i<=m; i++)
        for(int j=0; j<i; j++)
            v2.push_back(dp2[i]-dp2[j]);

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    long long ans = 0;
    for(auto p : v1){
        long long lb = lower_bound(v2.begin(), v2.end(), T-p) - v2.begin();
        long long ub = upper_bound(v2.begin(), v2.end(), T-p) - v2.begin();
        ans += ub-lb;
    }

    cout << ans;
}