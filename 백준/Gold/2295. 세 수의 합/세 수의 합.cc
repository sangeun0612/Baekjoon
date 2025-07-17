#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
 
    vector<int> v;
    for(int i=0; i<N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    unordered_set<int> s;
    for(auto p1 : v)    
        for(auto p2 : v) s.insert(p1+p2);

    int ans = 0;
    for(auto p1 : v)
        for(auto p2 : v) 
            if(s.find(p2-p1) != s.end())
                ans = max(ans, p2);

    cout << ans;
}