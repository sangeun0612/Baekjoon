#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000001];
vector<int> lis;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    lis.push_back(a[0]);

    for(int i = 1; i < n; i++) {
        if(a[i] > lis.back()) {
            lis.push_back(a[i]); // 증가하는 경우 LIS 확장
        } else {
            // 현재 수 a[i]가 들어갈 자리를 이분 탐색으로 찾아 교체
            auto it = lower_bound(lis.begin(), lis.end(), a[i]);
            *it = a[i];
        }
    }

    cout << lis.size(); // LIS의 길이 출력
}