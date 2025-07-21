#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
#define X first
#define Y second

int chk[1001];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> v;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++){
            int num;
            cin >> num;
            v.push_back({num, i});
        }
    sort(v.begin(), v.end());
    
    int ans = INT_MAX, cnt = 0, e = 0;
    for(int s=0; s < v.size(); s++){
        while(cnt < N && e < v.size()){
            if(!chk[v[e].Y]) cnt++;
            chk[v[e].Y]++;
            e++;
        }
        if(cnt != N) break;
        ans = min(ans, v[e-1].X - v[s].X);
        chk[v[s].Y]--;
        if(!chk[v[s].Y]) cnt--;
    }
    
    cout << ans;
} 