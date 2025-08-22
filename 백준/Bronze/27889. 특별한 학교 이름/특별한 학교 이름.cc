#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string N;
    cin >> N;
    if(N == "NLCS") cout <<"North London Collegiate School";
    else if(N == "BHA") cout <<"Branksome Hall Asia";
    else if(N == "KIS") cout <<"Korea International School";
    else if(N == "SJA") cout <<"St. Johnsbury Academy";
}