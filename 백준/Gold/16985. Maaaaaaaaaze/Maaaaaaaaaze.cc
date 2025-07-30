#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

int board1[5][5][5];  //원본
int board2[5][5][5];  //회전 결과
int board3[5][5][5];  //회전된 판을 섞은 결과

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

void rotate(int num){
    int tmp[5][5]={};

    for(int i=0; i<5; ++i)
        for(int j=0; j<5; ++j)
            tmp[j][4-i] = board2[num][i][j];
    
    for(int i=0; i<5; ++i)
        for(int j=0; j<5; ++j)
            board2[num][i][j] = tmp[i][j];
}

int bfs(){
    int dist[5][5][5]={};
    queue<tuple<int, int, int>> q;

    if(board3[0][0][0] == 0 || board3[4][4][4] == 0) return INT_MAX;

    dist[0][0][0] = 1;
    q.push({0,0,0});

    while(!q.empty()){
        int x, y, z;
        tie(x, y, z) = q.front(); q.pop();
        for(int dir=0; dir<6; ++dir){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nz = z + dz[dir];
            if(nx < 0 || nx >=5 || ny < 0 || ny >= 5 || nz < 0 || nz >= 5) continue;
            if(board3[nx][ny][nz] == 0 || dist[nx][ny][nz] != 0) continue;
            if(nx == 4 && ny == 4 && nz == 4) return dist[x][y][z];
            dist[nx][ny][nz] = dist[x][y][z]+1;
            q.push({nx, ny, nz});
        }
    }

    return INT_MAX;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0; i<5; ++i)
        for(int j=0; j<5; ++j)
            for(int k=0; k<5; ++k)
                cin >> board1[i][j][k];
    
    int ans = INT_MAX;
    for(int tmp=0; tmp<1024; ++tmp){
        for(int i=0; i<5; ++i)
            for(int j=0; j<5; ++j)
                for(int k=0; k<5; ++k)
                    board2[i][j][k] = board1[i][j][k];
        
        int brute = tmp;
        for(int i=0; i<5; ++i){  //5개 판의 방향 정하기    
            int dir = brute%4;
            brute /= 4;
            while(dir--) rotate(i);
        }

        //5개 판 섞고 bfs 돌리기
        int order[5] = {0, 1, 2, 3, 4};
        do{
            for(int i=0; i<5; ++i)
                for(int j=0; j<5; ++j)
                    for(int k=0; k<5; ++k)
                        board3[i][j][k] = board2[order[i]][j][k];
            ans = min(ans, bfs());
        }while(next_permutation(order, order+5));
    }

    if(ans == INT_MAX) ans = -1;
    cout << ans;
}