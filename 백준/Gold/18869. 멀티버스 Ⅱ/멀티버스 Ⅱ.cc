#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int arr[100][10000];
int M, N;

void compress(int a[]){
    vector<int> v(a, a+N);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i=0; i<N; i++){
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> M >> N;
    
    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) cin >> arr[i][j];
        compress(arr[i]);
    }
    
    int ans=0;
   
    for(int i=0; i<M-1; i++)
        for(int j=i+1; j<M; j++){
            int flag=1;
            for(int k=0; k<N; k++){
                if(arr[i][k] != arr[j][k]) flag = 0;
            }
            ans += flag;
        }
                    

    cout << ans;
}