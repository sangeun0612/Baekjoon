#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int N;
    stack <int> S;

    cin >> N;

    for(int i=0; i<N; i++){
        string op;
        cin >> op;

        if(op == "push"){
            int v;
            cin >> v;
            S.push(v);
        }
        else if(op == "pop"){
            if(S.empty()) cout << "-1\n";
            else {
                cout << S.top() << "\n";
                S.pop();
            }
        }
        else if(op == "size"){
            cout << S.size() << "\n";
        }
        else if(op == "empty"){
            if(S.empty()) cout << "1\n";
            else cout << "0\n";
        }
        else if(op == "top"){
            if(S.empty()) cout << "-1\n";
            else cout << S.top() << "\n";
        }
    }
}