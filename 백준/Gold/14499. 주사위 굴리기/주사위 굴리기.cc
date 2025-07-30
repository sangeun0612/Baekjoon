#include <iostream>
using namespace std;

int N, M, x, y, K;  
int board[20][20];
int dice[7];

int idx[4][4] = {
    {1, 4, 6, 3},  //동쪽으로 굴리기
    {1, 3, 6, 4},  //서쪽으로 굴리기
    {1, 5, 6, 2},  //북쪽으로 굴리기
    {1, 2, 6, 5}   //남쪽으로 굴리기
};

void roll(int cmd){
    int tmp[7]={};
    for(int i=1; i<=6; ++i) tmp[i] = dice[i];

    for(int i=0; i<4; ++i) tmp[idx[cmd][i]] = dice[idx[cmd][(i+1)%4]];
    
    for(int i=1; i<=6; ++i) dice[i]=tmp[i];
}

void score(int cmd){
    int nx = x, ny = y;
    if(cmd == 1) ++ny;
    else if(cmd == 2) --ny; 
    else if(cmd == 3) --nx;
    else if(cmd == 4) ++nx;

    if(nx < 0 || nx >= N || ny < 0 || ny >= M) return; 
    x = nx, y = ny;
    roll(cmd-1);
    if(board[nx][ny] == 0) board[nx][ny] = dice[6];
    else{
        dice[6] = board[nx][ny];
        board[nx][ny] = 0;
    }

    cout << dice[1] << "\n";
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> x >> y >> K;
    for(int i=0; i<N; ++i)
        for(int j=0; j<M; ++j) cin >> board[i][j];

    while(K--){
        int cmd;
        cin >> cmd;
        score(cmd);
    }
}