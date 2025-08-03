#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int N;
int score[20][20];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++) cin >> score[i][j];
    
    vector<int> brute(N);
    fill(brute.begin()+N/2, brute.end(), 1);
    int ans = INT_MAX;
    do{
        int score1 = 0, score2 = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(brute[i] == 0 && brute[j] == 0) score1 += score[i][j];
                else if(brute[i] == 1 && brute[j] == 1) score2 += score[i][j];
            }
        }
        ans = min(ans, abs(score1-score2));
    }while(next_permutation(brute.begin(), brute.end()));

    cout << ans;
}