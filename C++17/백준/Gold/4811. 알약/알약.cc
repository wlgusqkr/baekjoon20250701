#include <bits/stdc++.h>
using namespace std;

long long dp[32][32]; // W, H

long long go(int W, int H) {
    if(W < 0 || H < 0) return 0;
    if(W == 0 && H == 0) return 1;
    long long &ret = dp[W][H];
    if(ret != 0) return ret;
    
    ret = go(W - 1, H + 1) + go(W, H - 1);
    
    return ret;
}

int main() {
    
    while(true) {
        int i_num;
        cin >> i_num;
        if(i_num == 0) break;
        
        cout << go(i_num, 0) << '\n';
    }
}
