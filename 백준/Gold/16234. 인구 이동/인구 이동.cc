#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int N, L, R;
int board[51][51];
bool vis[51][51];  //반복적 초기화가 필요할듯?
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int ans = 0;

bool bfs(int x, int y){
    vector<pair<int,int>> tmp;  //연결된 나라의 좌표 저장
    queue<pair<int,int>> q;
    int sum = board[x][y];
    tmp.push_back({x, y});
    vis[x][y] = true;
    q.push({x, y});
    while(!q.empty()){
        pair<int, int> cur = q.front(); q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if(vis[nx][ny]) continue;

            if(L <= abs(board[cur.X][cur.Y]-board[nx][ny]) && abs(board[cur.X][cur.Y]-board[nx][ny]) <= R){
                sum += board[nx][ny];
                tmp.push_back({nx, ny});
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    if(tmp.size() == 1) return false;

    int val = sum/tmp.size();
    for(auto p : tmp) board[p.X][p.Y] = val;
    return true;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> L >> R;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++) cin >> board[i][j];

    while(1){
        bool check = false;
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                if(!vis[i][j]) check |= bfs(i, j);

        for(int i=0; i<N; i++) fill(vis[i], vis[i]+N, false);

        if(!check) break;  //인구 이동이 없었다면 종료
        ans++;
    }

    cout << ans;
}