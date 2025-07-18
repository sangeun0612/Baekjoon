#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[100'000];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i=0; i<N; i++) cin >> a[i];

    int ans1=100'000'001, ans2=100'000'001;
    for(int i=0; i<N; i++){
        int index = lower_bound(a, a+N, -a[i]) - a;

        if(index-1 >= 0 && (index-1) != i && abs(a[i]+a[index-1]) < (abs(ans1+ans2))) ans1 = a[i], ans2 = a[index-1];
        
        if(index != N && index != i && abs(a[i]+a[index]) < (abs(ans1+ans2))) ans1 = a[i], ans2 = a[index];
                
        if(index+1 < N && (index+1) != i && abs(a[i]+a[index+1]) < (abs(ans1+ans2))) ans1 = a[i], ans2 = a[index+1];
    }
    cout << ans1+ans2;
}