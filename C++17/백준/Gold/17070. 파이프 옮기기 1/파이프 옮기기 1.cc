#include <bits/stdc++.h>
using namespace std;

int dy[3] = { 1, 1, 0};
int dx[3] = { 0, 1, 1};

int N, arr[18][18], dp[18][18][3]; // 0 가로, 1 대각 2 세로

int main() {
    cin >> N;
    for(int i = 1 ; i <= N; i++) {
        for(int j = 1 ; j <= N; j++) {
            cin >> arr[i][j];
        }
    }
    
    dp[1][2][0] = 1;
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(i == 1 && j == 2) continue;
            if(arr[i][j] == 1) continue;
            dp[i][j][0] = dp[i][j-1][0] + dp[i][j-1][1]; // 가로
            if(arr[i-1][j] != 1 && arr[i][j -1 ] != 1) {
                dp[i][j][1] = dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2]; // 대각
            }
            dp[i][j][2] = dp[i-1][j][1] + dp[i-1][j][2]; // 세로
        }
    }
    cout << dp[N][N][0] + dp[N][N][1] + dp[N][N][2];
    
    
}
