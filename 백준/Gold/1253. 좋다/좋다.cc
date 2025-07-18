#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[2'000];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i=0; i<N; i++) cin >> a[i];
    sort(a, a+N);

    int ans=0;
    for(int i=0; i<N; i++){
        bool flag = false;
        for(int j=0; j<N && !flag; j++){
            if(j == i) continue;
            int x = a[i]-a[j];
            int idx = lower_bound(a, a+N, x)-a;
            while(idx < N && a[idx] == x) {
                if(idx != i && idx != j) {
                    flag = true;
                    ans++;
                    break;
                }
                idx++;
            }
        }
    }

    cout << ans;
}