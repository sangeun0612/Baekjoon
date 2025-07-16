#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    
    unordered_set<string> ss; 
    for(int i=1; i<=s.length(); i++){
        for(int j=0; j+i <= s.length(); j++){
            string temp = s.substr(j, i);
            ss.insert(temp);
        }
    }
    cout << ss.size();
}