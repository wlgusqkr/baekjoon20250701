#include <bits/stdc++.h>
using namespace std;

int dy[4] = { -1, 0, +1, 0 };
int dx[4] = { 0, +1, 0, -1 };

int N, M, dp[52][52], visited[52][52];
char arr[52][52];

int go(int y, int x) {
    if(arr[y][x] == 'H' || x >= M || x < 0 || y < 0 || y >= N) return 0;
    if(visited[y][x] == 1) {cout << -1; exit(0);}
    int &ret = dp[y][x];
    if(ret) return ret;
    
    visited[y][x] = 1;
    for(int i = 0 ; i < 4; i++) {
        int ny = y + dy[i]*((int) arr[y][x] - '0');
        int nx = x + dx[i]*((int) arr[y][x] - '0');
        ret = max(ret, go(ny, nx) + 1);
    }
    visited[y][x] = 0;
    
    return ret;
}
int main() {
    
    cin >> N >> M;

    for(int i = 0 ; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf(" %c", &arr[i][j]);
        }
    }
    
    cout << go(0, 0);
    
    
    
    
    
}
