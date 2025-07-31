#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int N, K, L;
int board1[102][102];
vector<pair<int, char>> rot;  //회전 정보
deque<pair<int ,int>> snake = {{1,1}};

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for(int i=0; i<K; ++i){
        int x, y;
        cin >> x >> y;
        board1[x][y] = 9;
    }
    
    cin >> L;
    for(int i=0; i<L; ++i){
        int t; char d;
        cin >> t >> d;
        rot.push_back({t, d});
    }

    long long ans=0;
    int idx=0;
    int dir = 1;  //0 = 북쪽, 1 = 동쪽, 2 = 남쪽, 3 = 서쪽
    while(1){
        if(idx < rot.size() && ans == rot[idx].X){  //방향 회전
            if(rot[idx].Y == 'L') dir = (dir+3)%4;
            else dir = (dir+1)%4;
            ++idx;
        }

        //머리 전진
        int x = snake[0].X + dx[dir];
        int y = snake[0].Y + dy[dir];
        snake.push_front({x, y});
        ++ans;

        if(snake[0].X <= 0 || snake[0].X >= N+1 || snake[0].Y <= 0 || snake[0].Y >= N+1) break;  //벽 충돌
        if(snake.size() >= 2)  // 몸 충돌
            if(find(snake.begin()+1, snake.end(), snake[0]) != snake.end()) break;

        if(board1[snake[0].X][snake[0].Y] == 9) board1[snake[0].X][snake[0].Y] = 0;
        else snake.pop_back(); 
    }
    cout << ans;
}