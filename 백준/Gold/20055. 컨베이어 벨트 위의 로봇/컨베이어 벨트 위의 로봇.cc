#include <iostream>
using namespace std;

int N, K;
int board[2][101]; //1-indexed
bool robot[101];  //1-indexed
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void rotate(){
    int nx = 0, ny = 1;
    int dir = 0, prev1 = board[1][1];
    //컨베이어 벨트 회전
    for(int i=0; i<2; i++){
        for(int j=1; j<=N; j++){
            swap(board[nx][ny], prev1);
            nx += dx[dir];
            ny += dy[dir];
            if(dir == 0 && ny == N) dir++;
            else if(dir == 1 && nx == 1) dir++;
            else if(dir == 2 && ny == 0) dir++;
        } 
    }

    //로봇 회전
    bool prev2 = false;
    for(int i=1; i<N; i++) swap(robot[i], prev2);
}

void move(int& cnt){
    for(int i=N-1; i>=1; i--){
        if(robot[i] && !robot[i+1] && board[0][i+1] >= 1){  //로봇이 움직일 수 있을 때
            swap(robot[i], robot[i+1]);
            if(--board[0][i+1] == 0) cnt++;
            if(i == N-1) robot[N] = false;
        }
    }
    
}

void load(int& cnt){
    if(!robot[1] && board[0][1] >= 1){  //로봇을 올려놓을 수 있을 때
        robot[1] = true;
        if(--board[0][1] == 0) cnt++;
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for(int i=1; i<=N; i++) cin >> board[0][i];
    for(int i=N; i>=1; i--) cin >> board[1][i];
    
    int cnt=0, ans=1;
    while(1){
        rotate();
 
        move(cnt);
        if(cnt >= K) break;
  
        load(cnt);
        if(cnt >= K) break;
        ans++;
    }   
    cout << ans;
}