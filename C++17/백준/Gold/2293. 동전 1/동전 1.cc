#include <bits/stdc++.h>
using namespace std;

int n, k, arr[103], dp[100003];

int main() {
    
    cin >> n >> k;

    for(int i = 1 ; i <= n; i++) {
        cin >> arr[i];
    }

    dp[0] = 1;
    
    for(int i = 1; i <= n; i++) {
        for(int j = arr[i]; j <= k; j++) {
            dp[j] = dp[j] + dp[j - arr[i]];
        }
    }
    cout << dp[k];
    
    
}
