#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define X first
#define Y second

int R, C, T;
int board[50][50];
//시계 방향
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

//반시계 방향
int cdx[4] = {0, 1, 0, -1};
int cdy[4] = {1, 0, -1, 0};

vector<pair<int,int>> v;
queue<pair<int,int>> q;

void bfs(){
    int tmp[50][50]={};  //원본 보드에 더할 확산된 미세먼지 개수
    while(!q.empty()){
       pair<int,int> cur = q.front(); q.pop();
       for(int dir=0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if(board[nx][ny] == -1) continue;
            tmp[nx][ny] += board[cur.X][cur.Y]/5;
            tmp[cur.X][cur.Y] -= board[cur.X][cur.Y]/5;
       }
    }

    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++) board[i][j] += tmp[i][j];
}

void clockwise(){
    int prev = 0, dir = 0;
    int nx = v[0].X, ny = v[0].Y+1;
    while(!(nx == v[0].X && ny == v[0].Y)){
        swap(board[nx][ny], prev);
        nx += dx[dir];
        ny += dy[dir];
            
        if(dir == 0 && ny == C-1) dir++;
        else if(dir == 1 && nx == 0) dir++;
        else if(dir == 2 && ny == 0) dir++;
    }
}

void counter_clockwise(){
    int prev = 0, dir = 0;
    int nx = v[1].X, ny = v[1].Y+1;
    while(!(nx == v[1].X && ny == v[1].Y)){
        swap(board[nx][ny], prev);
        nx += cdx[dir];
        ny += cdy[dir];
            
        if(dir == 0 && ny == C-1) dir++;
        else if(dir == 1 && nx == R-1) dir++;
        else if(dir == 2 && ny == 0) dir++;
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C >> T;

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> board[i][j];
            if(board[i][j] == -1) v.push_back({i,j});
        }
    }

    while(T--){
        for(int i=0; i<R; i++)
            for(int j=0; j<C; j++) 
                if(board[i][j] > 0) q.push({i,j});
        bfs();
        clockwise();
        counter_clockwise();
    }
        
    int ans=2;  //공기 청정기 칸 제외
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++) ans += board[i][j];
    cout << ans;
}