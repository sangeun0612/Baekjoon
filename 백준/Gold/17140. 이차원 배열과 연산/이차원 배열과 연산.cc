#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int r, c, k;
int row_size=3, col_size=3;
int board[101][101];  //1-indexed

void R(){
    for(int i=1; i<=row_size; i++){
        int count[101] = {};
        int idx = 1;
        vector<pair<int,int>> v;  //빈도, 수

        for(int j=1; j<=col_size; j++) 
            if(board[i][j]) count[board[i][j]]++;
         
        for(int j=1; j<=100; j++)
            if(count[j]) v.push_back({count[j], j});
        
        sort(v.begin(), v.end());
        for(auto p : v){
            board[i][idx++] = p.Y;
            board[i][idx++] = p.X;
            if(idx >= 101) break;
        }
        
        int size;
        if(v.size()*2 > 100) size = 100;
        else size = v.size()*2;
        col_size = max(col_size, size);
        if(idx <= 100) fill(board[i]+idx, board[i]+1+col_size, 0);
    }
}

void C(){
    for(int i=1; i<=col_size; i++){
        int count[101] = {};
        int idx = 1;
        vector<pair<int,int>> v;  //빈도, 수

        for(int j=1; j<=row_size; j++) 
            if(board[j][i]) count[board[j][i]]++;
        
        for(int j=1; j<=100; j++)
            if(count[j]) v.push_back({count[j], j});
        
        sort(v.begin(), v.end());
        for(auto p : v){
            board[idx++][i] = p.Y;
            board[idx++][i] = p.X;
            if(idx >= 101) break;
        }
        
        int size;
        if(v.size()*2 > 100) size = 100;
        else size = v.size()*2;
        row_size = max(row_size, size);
        for(int j=idx; j<=row_size; j++) board[j][i] = 0;
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> r >> c >> k;
    for(int i=1; i<=3; i++)
        for(int j=1; j<=3; j++) cin >> board[i][j];

    int T = 0;
    while(T <= 100){
        if(board[r][c] == k) break;
        if(row_size >= col_size) R();
        else C();
        T++;
    }

    if(T > 100) T = -1;
    cout << T;
}   

//최대 반복 횟수 k X 100(행or열의 개수 r, c) X 빈도 저장 X 정렬O(nlogn)
//100 * 100 * {100 + 100 + (100 * 7) + 100} = 10'000 * 1'000 = 10'000'000