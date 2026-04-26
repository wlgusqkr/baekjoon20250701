#include <bits/stdc++.h>
using namespace std;

int INF = 1e9;
int T, W, arr[1004], dp[1004][32][3];

int go(int t, int w, int loc) {
    if(t >= T) return 0;
    if(W < w) return -INF;
    int &ret = dp[t][w][loc];
    if(ret != -1) return ret; // 아하 띄방

    // 움직인 값
    // 움직이지 않은 값
    ret = max(go(t+1, w, loc), go(t+1, w+1, loc ^ 1));
    
    if(loc == arr[t]) ret += 1;
    
    return ret;
}
int main() {
    cin >> T >> W;
    
    memset(dp, -1, sizeof(dp));
    
    for(int i = 0 ; i < T; i++) {
        int tmp;
        cin >> tmp;
        arr[i] = tmp - 1;
    }
    
    cout << max(go(0, 0, 0), go(0, 1, 1));  // 두 번째는 w=1, loc=1
}
