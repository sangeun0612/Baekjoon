#include <iostream>
#include <queue>
using namespace std;
#define X first 
#define Y second
int n, w, L;
int a[1000];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> w >> L;
    for(int i=0; i<n; i++) cin >> a[i];

    int ans=0, idx=0, weight=0;
    queue<pair<int, int>> q;  //다리에 올라와 있는 트럭의 정보(무게, 위치)
    while(1){
        queue<pair<int,int>> tmp;
        while(!q.empty()){
            auto info = q.front(); q.pop();
            if(info.Y+1 >= w) {
                weight -= info.X;
                continue;
            }
            tmp.push({info.X, info.Y+1});
        }
        q = tmp;

        ++ans;  //시간 증가
        if(q.size() == 0 && idx >= n) break;

        if(q.size()+1 <= w){
            if(idx < n && weight+a[idx] <= L){
                weight += a[idx]; 
                q.push({a[idx], 0});
                ++idx;
            }
        }
    }
    cout << ans;
}