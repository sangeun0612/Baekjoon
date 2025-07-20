#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool a[100'001];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> v;
    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    v.push_back(0);

    long long ans = 0;
    int s = 0, e = 0;
    while(1){
        if(!a[v[e]]){
            a[v[e]] = true;
            ans += (e-s)+1;
            e++;
        }
        else a[v[s++]] = false;
        if(e == v.size()-1) break;
    }

    cout << ans;
} 