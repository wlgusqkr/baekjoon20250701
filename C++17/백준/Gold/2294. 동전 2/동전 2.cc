#include <bits/stdc++.h>
using namespace std;

int n, k, arr[103], dp[100003];

int INF = 999999;
int main() {
    
    cin >> n >> k;
    fill(dp, dp + 100003, INF);
    for(int i = 0 ; i < n; i++) {
        cin >> arr[i];
        dp[arr[i]] = 1;
    }
    for(int i = 1 ; i <= k; i++) {
        for(int j = 0 ; j < n; j++) {
            if(i - arr[j] >= 0) dp[i] = min(dp[i-arr[j]]+1, dp[i]);
        }
    }
    
    if(dp[k] == INF) cout << -1;
    else cout << dp[k];
    
    
}
