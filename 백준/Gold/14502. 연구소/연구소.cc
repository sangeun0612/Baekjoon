#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int N, M;
int board[8][8], board2[8][8];
int vis[8][8], vis2[8][8];
int cnt, cnt2;  //안전 영역의 개수
queue<pair<int,int>> q, q2;
vector<pair<int,int>> v;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void bfs(){
    while(!q2.empty()){
        pair<int,int> cur = q2.front(); q2.pop();
        for(int dir=0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(vis2[nx][ny] == 1 || board2[nx][ny] == 1) continue;
            board2[nx][ny] = 2;
            cnt2--;
            vis2[nx][ny] = 1;
            q2.push({nx, ny});
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> board[i][j];
            if(board[i][j] == 0){
                v.push_back({i,j});
                cnt++;
            }
            else if(board[i][j] == 2){
                vis[i][j] = 1;
                q.push({i,j});
            }
        }
    }


    vector<int> brute(v.size(), 0);
    fill(brute.end()-3, brute.end(), 1);
    int ans = 0;
    do{
        //원본 복사
        q2 = q, cnt2 = cnt;
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++){
                board2[i][j] = board[i][j];
                vis2[i][j] = vis[i][j];
            }
        
        //기둥 정하기
        for(int i=0; i<brute.size(); i++)
            if(brute[i] == 1) {
                board2[v[i].X][v[i].Y] = 1;
                cnt2--;
            }

        bfs();
        ans = max(ans, cnt2);
    }while(next_permutation(brute.begin(), brute.end()));

    cout << ans;
}