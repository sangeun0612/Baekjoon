#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
#define X first
#define Y second

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int K, L;
    cin >> K >> L;

    unordered_map<string, int> m;
    for(int i=0; i<L; i++){
        string s;
        cin >> s;
        m[s] = i;
    }

    vector<pair<string,int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), [](auto& a, auto& b) { return a.Y < b.Y;});

    int en = min(K, (int)v.size());

    for(int i=0; i<en; i++) cout << v[i].X << "\n";
}