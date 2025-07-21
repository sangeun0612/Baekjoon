#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int arr[1'000'005];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i=0; i<n; i++){
        int st, en;
        cin >> st >> en;
        for(int j=st; j < en; j++) arr[j]++;
    }

    int en=0, tot=0;
    for(int st=0; st < 1'000'000; st++) {
        while(en < 1'000'000 && tot < k) tot += arr[en++];
        if(tot == k) {
            cout << st << ' ' << en;
            return 0;
        }
        if(en == 1'000'000) break;
        tot -= arr[st];
    }

    cout << 0 << ' ' << 0;
    return 0;
} 