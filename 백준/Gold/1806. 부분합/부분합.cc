#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int a[100'000];
int mn = INT_MAX;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, S;
    cin >> N >> S;
    for(int i=0; i<N; i++) cin >> a[i];
    int tot = a[0];

    int en=0;
    for(int st=0; st<N; st++){
        while(en < N && tot < S) {
            en++;
            if(en != N) tot += a[en];
        }
        if(en == N) break;
        mn = min(mn, en-st+1);
        tot -= a[st];
    }

    if(mn == INT_MAX) mn = 0;
    cout << mn;
}