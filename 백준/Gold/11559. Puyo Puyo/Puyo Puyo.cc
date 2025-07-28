#include <iostream>
#include <queue>
using namespace std;
#define X first
#define Y second

char board[14][8];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
bool isPuyo;

void bfs(){
    bool vis[14][8] = {};

    
    for(int i=0; i<12; i++){
        for(int j=0; j<6; j++){
            if(!vis[i][j] && board[i][j]!='.'){
                queue<pair<int, int>> Q;
                vector<pair<int, int>> v;
                vis[i][j] = true;
                Q.push({i, j});
                v.push_back({i, j});
                
                while(!Q.empty()){
                    pair<int, int> cur = Q.front(); Q.pop();
                    for(int dir = 0; dir<4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
                        if(vis[nx][ny]) continue;
                        if(board[nx][ny] == board[i][j]){
                            v.push_back({nx, ny});
                            vis[nx][ny] = true;
                            Q.push({nx, ny});
                        }
                    }    
                }
                if(v.size() >= 4) {
                    for(auto p : v) board[p.X][p.Y] = '.';
                    isPuyo = true;
                }
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0; i<12; i++)
        for(int j=0; j<6; j++) cin >> board[i][j];
    
    int ans = 0;
    do{
        isPuyo = false;
        bfs();
        for(int i=0; i<6; i++){
            int writeRow = 11;
            for(int j=11; j>=0; j--){
                if(board[j][i]!='.'){
                    board[writeRow][i] = board[j][i];
                    if(writeRow!=j) board[j][i] = '.';
                    writeRow--;
                } 
            }
        }

        if(isPuyo) ans++;
    }while(isPuyo);
    cout << ans;
}