#include <iostream>
#include <vector>
using namespace std;

int N;
int board[105][105];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    while(N--){
        int x, y, d, g;
        cin >> x >> y >> d >> g;

        vector<int> v;
        v.push_back(d);
        board[y][x]=1;
        
        while(g--){
            int size = v.size();
            for(int i = size-1; i>=0; i--) v.push_back((v[i]+1)%4);
        }

        for(auto dir : v){
            if(dir == 0) x++;
            else if(dir == 1) y--;
            else if(dir == 2) x--;
            else y++;
            board[y][x] = 1;
        }
    }

    int cnt = 0;
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            if(!board[i][j]) continue;
            if(board[i+1][j] && board[i][j+1] && board[i+1][j+1]) cnt++;
        }
    }
    cout << cnt;
}