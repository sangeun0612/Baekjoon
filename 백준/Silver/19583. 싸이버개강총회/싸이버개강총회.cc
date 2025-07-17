#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int ttoi(string time){
    int t=0;
    string h, m;

    h = time.substr(0, 2);
    m = time.substr(3, 2);

    t = (60*stoi(h)+stoi(m));
    return t;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string S, E, Q;
    cin >> S >> E >> Q;

    int st_t, end_t, stream_t;
    st_t = ttoi(S);
    end_t = ttoi(E);
    stream_t = ttoi(Q);

    unordered_set<string> s;  
    int ans = 0;
    while(true){
        string time, name;
        cin >> time >> name;
        if(cin.eof() == true) break;

        if(ttoi(time) <= st_t) s.insert(name);
        else if(end_t <= ttoi(time) && ttoi(time) <= stream_t)
            if(s.erase(name)) ans++;
    }

    cout << ans;
}