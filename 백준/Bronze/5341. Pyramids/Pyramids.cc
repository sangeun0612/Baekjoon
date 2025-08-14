#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    while(1){
        cin >> N;
        if(N==0) break;
        int sum=0;
        for(int i=N; i>=1; i--) sum += i;
        cout << sum << "\n";
    }
}