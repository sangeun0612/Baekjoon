#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long a[5000];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for(int i=0; i<N; i++) cin >> a[i];

    sort(a, a+N);

    long long ans1 = 1'000'000'001, ans2 = 1'000'000'001, ans3 = 1'000'000'001;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i==j) continue;
            int index = lower_bound(a, a+N, -(a[i]+a[j]))-a;

            if(index-1 >= 0 && index-1 != i && index-1 != j)
                if(abs(a[i]+a[j]+a[index-1]) < abs(ans1+ans2+ans3))
                    ans1=a[i], ans2=a[j], ans3=a[index-1];
            if(index < N && index != i && index != j)
                if(abs(a[i]+a[j]+a[index]) < abs(ans1+ans2+ans3))
                    ans1=a[i], ans2=a[j], ans3=a[index];
            if(index+1 < N && index+1 != i && index+1 != j)
                if(abs(a[i]+a[j]+a[index+1]) < abs(ans1+ans2+ans3))
                    ans1=a[i], ans2=a[j], ans3=a[index+1];
        }
    }

    long long ans[3] = {ans1, ans2, ans3};
    sort(ans, ans+3);
    cout << ans[0] << " " << ans[1] << " " << ans[2];
}