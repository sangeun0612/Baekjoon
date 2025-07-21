#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[200'001];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    vector<int> v;
    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }

    int ans = 0, e=0;
    for(int s=0; s < v.size(); s++){
        while(e < v.size() && a[v[e]]+1 <= K){
            a[v[e]]++;
            ans = max(ans, (e-s)+1);
            e++;
        }
        a[v[s]]--;
    }
    
    cout << ans;
} 