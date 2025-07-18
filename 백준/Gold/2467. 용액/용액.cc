#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int a[100'000];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    
    for(int i=0; i<N; i++) cin >> a[i];

    int ans1=0, ans2=0, tot=INT_MAX;
    for(int i=0; i<N; i++){
        int index = lower_bound(a, a+N, -a[i]) - a;

        if(index-1 >= 0 && (index-1) != i){
            if(tot != min(tot, abs(a[i]+a[index-1]))){
                ans1 = a[i], ans2 = a[index-1];
                tot = abs(a[i]+a[index-1]);
            }
        }
        
        if(index != N && index != i){
            if(tot != min(tot, abs(a[i]+a[index]))){
                ans1 = a[i], ans2 = a[index];
                tot = abs(a[i]+a[index]);
            }
        }

        if(index+1 < N && (index+1) != i)
            if(tot != min(tot, abs(a[i]+a[index+1]))){
                ans1 = a[i], ans2 = a[index+1];
                tot = abs(a[i]+a[index+1]);
            }
    }
    
    if(ans1 < ans2) cout << ans1 << " " << ans2;
    else cout << ans2 << " " << ans1;
}