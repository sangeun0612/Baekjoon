#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int N, M, K;
int board[51][51], tmp[51][51];  //1-indexed
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void rot(int r, int c, int s){
    int row_start = r-s, row_end = r+s, col_start = c-s, col_end = c+s; 
    while(row_start < row_end){
        int nx = row_start, ny = col_start;
        int prev = tmp[row_start+1][col_start], dir = 0;
        while(1){
            swap(tmp[nx][ny], prev);
            if(nx == row_start+1 && ny == col_start) break;
            nx += dx[dir];
            ny += dy[dir];

            if(dir == 0 && ny == col_end) dir++;
            else if(dir == 1 && nx == row_end) dir++;
            else if(dir == 2 && ny == col_start) dir++;
        }
        row_start++, col_start++;
        row_end--, col_end--;
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++) cin >> board[i][j];

    vector<tuple<int,int,int>> v;
    for(int i=0; i<K; i++){
        int r, c, s;
        cin >> r >> c >> s;
        v.push_back({r,c,s});
    }

    vector<int> brute;
    for(int i=0; i<v.size(); i++) brute.push_back(i);
    int ans=INT_MAX;
    do{
        for(int i=1; i<=N; i++)
            for(int j=1; j<=M; j++)
                tmp[i][j] = board[i][j];

        for(int i=0; i<brute.size(); i++){
            int r, c, s;
            tie(r, c, s) = v[brute[i]];
            rot(r, c, s);
        }

        for(int i=1; i<=N; i++){
            int sum = 0;
            for(int j=1; j<=M; j++) sum += tmp[i][j];
            ans = min(ans, sum);
        }
    }while(next_permutation(brute.begin(), brute.end()));
    cout << ans;
}