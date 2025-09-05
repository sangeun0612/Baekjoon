#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            cout << "*";
        }
        cout << "\n";
    }

}