#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int month = 8+7*(N-1);
    int year = 2024 + month/13;
    if(month%12 != 0) month = month%12;
    else month = 12;
    cout << year << " " << month;
}