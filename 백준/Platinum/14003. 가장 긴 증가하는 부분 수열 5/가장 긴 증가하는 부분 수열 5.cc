#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[1000001];
int pos[1000001]; 

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> temp;
    for(int i=0; i<n; i++){
        auto it = lower_bound(temp.begin(), temp.end(), a[i]);
        int idx = it - temp.begin();

        if(it == temp.end()) temp.push_back(a[i]);  //LIS 수열에 없을 경우
        else *it = a[i];
        
        pos[i] = idx;
    }

    cout << temp.size() << "\n";

    vector<int> LIS;
    int target = temp.size()-1;
    for(int i = n-1; i >= 0; i--){
        if(pos[i] == target) {
            LIS.push_back(a[i]);
            target--;
        }
    }
    reverse(LIS.begin(), LIS.end());
    for(auto p : LIS) cout << p << " ";
} 