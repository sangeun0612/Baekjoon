#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int num[11];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for(int i=0; i<N; i++) cin >> num[i];

    vector<int> brute(N-1);
    int st = 0;
    for(int i=0; i<4; i++){
        int op;
        cin >> op;
        fill(brute.begin()+st, brute.begin()+st+op, i);
        st += op;
    }

    int mx = -1'000'000'000, mn = 1'000'000'000;
    do{
        int sum = num[0];
        for(int i=0; i<brute.size(); i++){
            if(brute[i] == 0) sum += num[i+1];
            else if(brute[i] == 1) sum -= num[i+1];
            else if(brute[i] == 2) sum *= num[i+1];
            else sum /= num[i+1];
        }

        mx = max(mx, sum);
        mn = min(mn, sum);
    }while(next_permutation(brute.begin(), brute.end()));

    cout << mx << "\n" << mn;
}