#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tot = 0;
    for(int i=0; i<4; i++){
        int n;
        cin >> n;
        tot += n;
    }

    if(tot+300 <= 1800) cout << "Yes";
    else cout << "No";
}