#include <iostream>
#include <algorithm>
using namespace std;

int a[2001], d[2001][2001];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N;
    for(int i=1; i<=N; i++) cin >> a[i];

    for(int i=1; i<=N; i++){
        d[i][i] = 1;
        if(a[i-1] == a[i]) d[i-1][i] = 1;
    }

    for(int gap=2; gap < N; gap++){
        for(int i=1; i <= N-gap; i++){
            int s = i, e = i+gap;
            if(a[s] == a[e] && d[s+1][e-1]) d[s][e] = 1; 
        }
    }

    cin >> M;
    while(M--){
        int s, e;
        cin >> s >> e;
        cout << d[s][e] << "\n";
    }
} 