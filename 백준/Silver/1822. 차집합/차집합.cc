#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int count1, count2;
    cin >> count1 >> count2;

    vector<int> v1, v2;
    for(int i=0; i<count1; i++) {
        int num;
        cin >> num;
        v1.push_back(num);
    }

    for(int i=0; i<count2; i++) {
        int num;
        cin >> num;
        v2.push_back(num);
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    vector<int> ans;
    for(auto p : v1)  
        if(!binary_search(v2.begin(), v2.end(), p)) 
            ans.push_back(p);
    
    cout << ans.size() << "\n";
    if(ans.size()) for(auto p : ans) cout << p << " ";
}