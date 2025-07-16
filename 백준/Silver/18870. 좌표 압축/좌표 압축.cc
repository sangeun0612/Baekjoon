#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int x[1'000'005];

vector<int> tmp, uni;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x[i];
        tmp.push_back(x[i]);
    }

    sort(tmp.begin(), tmp.end());
    for(int i=0; i<n; i++)
        if(i==0 || tmp[i-1] != tmp[i]) uni.push_back(tmp[i]);

    for(int i=0; i<n; i++) cout << lower_bound(uni.begin(), uni.end(), x[i]) - uni.begin() << " ";
}