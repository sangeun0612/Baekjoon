#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#define X first
#define Y second

bool ladder[32][12], ladder2[32][12];
vector<pair<int,int>> coords;
int N, M, H;

bool check(){
    for(int j=1; j<=N; j++){
        int cur = j;
        for(int i=1; i<=H; i++){
            if(ladder2[i][cur-1]) cur--;
            else if(ladder2[i][cur]) cur++; 
        }
        if(cur != j) return false;
    }
    return true;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> H;
    while(M--){
        int a, b;
        cin >> a >> b;
        ladder[a][b] = true;
    }

    for(int i=1; i<=H; i++){
        for(int j=1; j<N; j++){
            if(ladder[i][j-1] || ladder[i][j] || ladder[i][j+1]) continue;
            coords.push_back({i,j});
        }
    }

    for(int i=1; i<=H; i++)
        for(int j=1; j<=N; j++)
            ladder2[i][j] = ladder[i][j];

    if(check()){
        cout << 0;
        return 0;
    }

    int ans = INT_MAX;
    
    //1개 가로선
    if(coords.size() >= 1){
        vector<int> brute1(coords.size());
        fill(brute1.end()-1, brute1.end(), 1);
        do{
            for(int i=1; i<=H; i++)
                for(int j=1; j<=N; j++)
                    ladder2[i][j] = ladder[i][j];

            for(int i=0; i<brute1.size(); i++)
                if(brute1[i] == 1) ladder2[coords[i].X][coords[i].Y] = 1;
            
            if(check()) ans = min(ans, 1);
        }while(next_permutation(brute1.begin(), brute1.end()));
    }

    //2개 가로선
     if(coords.size() >= 2){
        vector<int> brute2(coords.size());
        fill(brute2.end()-2, brute2.end(), 1);
        do{
            for(int i=1; i<=H; i++)
                for(int j=1; j<=N; j++)
                    ladder2[i][j] = ladder[i][j];

            for(int i=0; i<brute2.size(); i++)
                if(brute2[i] == 1) ladder2[coords[i].X][coords[i].Y] = 1;
            
            if(check()) ans = min(ans, 2);
        }while(next_permutation(brute2.begin(), brute2.end()));
    }

    //3개 가로선
    if(coords.size() >= 3){
        vector<int> brute3(coords.size());
        fill(brute3.end()-3, brute3.end(), 1);
        do{
            for(int i=1; i<=H; i++)
                for(int j=1; j<=N; j++)
                    ladder2[i][j] = ladder[i][j];

            for(int i=0; i<brute3.size(); i++)
                if(brute3[i] == 1) ladder2[coords[i].X][coords[i].Y] = 1;
            
            if(check()) ans = min(ans, 3);

        }while(next_permutation(brute3.begin(), brute3.end()));
    }

    if(ans == INT_MAX) ans = -1;
    cout << ans;
}