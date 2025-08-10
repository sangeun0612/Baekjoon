#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#define X first
#define Y second

int N, M, tmp;
int board[50][50], dist[50][50];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

queue<pair<int,int>> q;

bool check(){
    tmp = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(dist[i][j] == -1 && (board[i][j] == 0 || board[i][j] == 2)) return false;
            tmp = max(tmp, dist[i][j]);
        }
    }
    return true;
}

bool bfs(){
    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        for(int dir = 0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if(dist[nx][ny] != -1 || board[nx][ny] == 1) continue;
            dist[nx][ny] = dist[cur.X][cur.Y]+1;
            q.push({nx, ny});
        }
    }

    if(!check()) return false; //바이러스가 퍼지지 못한 칸이 있을 때
    return true;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    vector<pair<int,int>> virus;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> board[i][j];
            if(board[i][j] == 2) virus.push_back({i,j});
        }
    }
    
    vector<int> brute(virus.size());
    fill(brute.end()-M, brute.end(), 1);
    int ans = INT_MAX;
    do{
        for(int i=0; i<N; i++) fill(dist[i], dist[i]+N, -1);
        for(int i=0; i<brute.size(); i++){
            if(brute[i] == 1){
                dist[virus[i].X][virus[i].Y] = 0;
                q.push({virus[i].X, virus[i].Y});
            }
        }
        if(bfs()) ans = min(ans, tmp);  //바이러스가 모든 칸에 퍼졌을 때   
    }while(next_permutation(brute.begin(), brute.end()));

    if(ans == INT_MAX) ans = -1;
    cout << ans;
} 

//바이러스를 놓을 수 있는 모든 경우의 수 x bfs
//10C4 x 2500