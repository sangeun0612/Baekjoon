#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int result[50][9];

int game(vector<int> brute){
    brute.insert(brute.begin()+3, 1);  //4번 타자는 1번 선수

    int score = 0, inning = 0, out = 0, idx = 0;
    while(inning < N){
        vector<int> v;  //주자 위치
        out = 0;
        while(out < 3){
            idx %= 9;
            if(result[inning][brute[idx]-1] == 0) { out++; idx++; }
            else if(result[inning][brute[idx]-1] == 1){
                int cnt=0;
                for(int i=0; i<v.size(); i++){
                    v[i]++;
                    if(v[i] == 4) cnt++;
                }
                while(cnt--) { v.erase(v.begin()); score++; }
                v.push_back(1);
                idx++;
            }
            else if(result[inning][brute[idx]-1] == 2){
                int cnt=0;
                for(int i=0; i<v.size(); i++){
                    v[i] += 2;
                    if(v[i] >= 4) cnt++;
                }
                while(cnt--) { v.erase(v.begin()); score++; }
                v.push_back(2);
                idx++;
            }
            else if(result[inning][brute[idx]-1] == 3){
                score += v.size();
                v.clear();
                v.push_back(3);
                idx++;
            }
            else {
                score += v.size()+1;
                v.clear();
                idx++;
            }
        }
        inning++;
    }

    return score;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<9; j++) cin >> result[i][j];

    vector<int> brute = {2, 3, 4, 5, 6, 7, 8, 9};
    int ans = 0;
    do{
        ans = max(ans, game(brute));
    }while(next_permutation(brute.begin(), brute.end()));

    cout << ans;
}