#include <iostream>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M, ans = 0;
    deque<int> DQ;
    
    cin >> N >> M;
    for(int i=1; i<=N; i++) DQ.push_back(i);
    
    int loc[50];
    for(int i = 0; i<M; i++) cin >> loc[i]; 
    
    for(int i=0; i<M; i++){
        int count = 0;
        
        while(DQ.front() != loc[i]){
            DQ.push_back(DQ.front());
            DQ.pop_front();
            count++;
        }
        
        if(count < (DQ.size()-count)) ans += count;
        else ans += (DQ.size() - count);
        
        DQ.pop_front();
        
        //cout << ans << "\n";
    }
    
    cout << ans;
}
/*
1회 9회

1 2 3 4 5 6 7 8 9 10

2 3 4 5 6 7 8 9 10 1 -> 3 4 5 6 7 8 9 10 1

1 3 4 5 6 7 8 9 10
10 1 3 4 5 6 7 8 9
9 10 1 3 4 5 6 7 8 -> 10 1 3 4 5 6 7 8

8 9 10 1 3 4 5 6 7
7 8 9 10 1 3 4 5 6 
6 7 8 9 10 1 3 4 5
5 6 7 8 9 10 1 3 4
*/