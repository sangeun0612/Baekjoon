#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int d[1001], a[1001], pre[1001];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i=1; i<=N; i++) cin >> a[i];
    fill(d+1, d+N+1, 1);

    for(int i = 1; i <= N; ++i){
        for(int j = 1; j < i; ++j){
            if(a[j] < a[i] && d[i] < d[j] + 1){
                d[i] = d[j] + 1;
                pre[i] = j;
            }
        }
    }

    int maxi;
    int maxd = *max_element(d+1, d+N+1);
    for(int i=1; i<=N; i++) 
        if(d[i] == maxd){
            maxi = i;
            break;
        }

    int cur = maxi;
    vector<int> v;
    while(cur){
        v.push_back(a[cur]);
        cur = pre[cur];
    }

    reverse(v.begin(), v.end());

    cout << maxd << "\n";
    
    for(auto p : v) cout << p << " ";
}