#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[4000], b[4000], c[4000], d[4000];
int ab[16000000], cd[16000000];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
  
    int cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            ab[cnt] = a[i] + b[j];
            cd[cnt++] = c[i] + d[j];
    }

    sort(ab, ab+n*n);
    sort(cd, cd+n*n);

    long long ans=0;
    for(int i=0; i<n*n; i++)
        ans += upper_bound(ab, ab+n*n, -cd[i]) - lower_bound(ab, ab+n*n, -cd[i]);

    cout << ans;
}