#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int A, B, C;
    int freq[10]={};
    cin >> A >> B >> C;

    int result = A*B*C;

    while(result > 0){
        freq[result%10]++;

        result /= 10;
    }

    for(int i=0; i<10; i++){
        cout << freq[i] << "\n";
    }
}