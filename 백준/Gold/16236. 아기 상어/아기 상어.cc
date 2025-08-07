#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int N;
int shark_size = 2, eat = 0, ans = 0;
int board[20][20];
int dist[20][20];
queue<pair<int,int>> q;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

bool bfs(){
    tuple<int,int,int> t = {INT_MAX, INT_MAX, INT_MAX};  //거리, x좌표, y좌표
    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        for(int dir=0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if(dist[nx][ny] != -1) continue;
            if(board[nx][ny] > shark_size) continue;
            if(board[nx][ny] != 0 && board[nx][ny] < shark_size) {  //먹이를 먹을 수 있을 때
                dist[nx][ny] = dist[cur.X][cur.Y]+1;
                t = min(t, {dist[nx][ny], nx, ny});
            }
            //먹이를 먹지 않고 이동만 할 때
            dist[nx][ny] = dist[cur.X][cur.Y]+1;
            q.push({nx, ny});
        }
    }

    int dist2, x, y;
    tie(dist2, x, y) = t;
    if(dist2 != INT_MAX){
        if(++eat == shark_size){
            eat = 0;
            shark_size++;
        }
        
        board[x][y] = 9;
        ans += dist[x][y];

        q.push({x, y});
        for(int i=0; i<20; i++) fill(dist[i], dist[i]+20, -1);
        dist[x][y] = 0;
        return true;
    }

    return false;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0; i<20; i++) fill(dist[i], dist[i]+20, -1);

    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){ 
            cin >> board[i][j];
            if(board[i][j] == 9) {
                dist[i][j] = 0;
                q.push({i,j});
            }
        }
    }

    board[q.front().X][q.front().Y] = 0;
    while(bfs()){
        board[q.front().X][q.front().Y] = 0;
    }
    cout << ans;
}