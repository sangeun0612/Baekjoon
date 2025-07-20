#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> v;
    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    v.push_back(0);

    int sum = v[0], ans = 0, st = 0, en = 1;
    while(1){
        if(sum == M) ans++;
        if(sum <= M) sum += v[en++]; 
        if(sum > M) sum -= v[st++];
        if(en == v.size()) break;
    }
    cout << ans;
}