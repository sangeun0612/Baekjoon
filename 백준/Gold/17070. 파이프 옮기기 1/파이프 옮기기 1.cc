#include <iostream>
using namespace std;

int N;
int board[17][17];  //1-indexed
int ans = 0;
int dx[3] = {0, 1, 1};
int dy[3] = {1, 1, 0};  //가로, 대각선, 세로

void move(int x, int y, int prev_dir){
    if(x == N && y == N){
        ans++;
        return;
    }

    for(int dir = 0; dir<3; dir++){
        if(dir == 0 && prev_dir == 2) continue;
        if(dir == 2 && prev_dir == 0) continue;
        
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(nx > N || ny > N) continue;
        if(board[nx][ny]) continue;
        if(dir == 1)
            if(board[nx-1][ny] || board[nx][ny-1]) continue;

        move(nx, ny, dir);
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++) cin >> board[i][j];
    
    move(1, 2, 0);
    cout << ans;
}