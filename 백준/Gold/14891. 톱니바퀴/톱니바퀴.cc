#include <iostream>
#include <deque>
using namespace std;

deque<int> wheel[4];

void rotate(int num, int dir){    
    int dirs[4]={};
    dirs[num] = dir;

    int idx = num;
    while(idx-1 >= 0 && wheel[idx][6] != wheel[idx-1][2]){  //왼쪽 톱니바퀴 돌리기
        dirs[idx-1] = -dirs[idx];
        --idx;
    }

    idx = num;
    while(idx+1 <= 3 && wheel[idx][2] != wheel[idx+1][6]){  //오른쪽 톱니바퀴 돌리기
        dirs[idx+1] = -dirs[idx];
        ++idx;
    }

    for(int i=0; i<4; i++){
        if(dirs[i] == 1){  //시계 방향 회전
            int tmp = wheel[i].back();
            wheel[i].pop_back();
            wheel[i].push_front(tmp);
        }
        else if(dirs[i] == -1){   //반시계 방향 회전
            int tmp = wheel[i].front();
            wheel[i].pop_front();
            wheel[i].push_back(tmp);
        }
    }
}   

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s[4];
    for(int i=0; i<4; ++i){
        cin >> s[i];
        for(int j=0; j<8; ++j){
            wheel[i].push_back(s[i][j]-'0');
        }
    }
        
    int k;
    cin >> k;
    for(int i=0; i<k; ++i){
        int num, dir;
        cin >> num >> dir;
        rotate(num-1, dir);
    }

    int ans=0;
    for(int i=0; i<4; ++i)
        if(wheel[i][0] == 1) ans += (1 << i);
    cout << ans;
}