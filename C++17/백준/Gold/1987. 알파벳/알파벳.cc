#include <bits/stdc++.h>
using namespace std;

int R, C, visited[22][22], ret;

int dy[4] = { -1, 0, +1, 0 };
int dx[4] = { 0, +1, 0, -1 };

char arr[22][22];

void go(int y, int x, int num, int cnt) {

    ret = max(ret, cnt);
    for(int i = 0 ; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if(ny >= R || ny < 0 || nx >= C || nx < 0 || visited[ny][nx] == 1) continue;
        int _next = (1 << (int)(arr[ny][nx] - 'A'));
        if((num & _next) == 0) go(ny, nx, num | _next, cnt + 1);
    }
    return;
}

int main() {
    
    cin >> R >> C;
    
    for(int i = 0 ; i < R; i++) {
        for(int j = 0; j < C; j++) {
            scanf(" %c", &arr[i][j]);
        }
    }
    
    go(0, 0, 1 << (((int)arr[0][0]) - 'A'), 1);
    
    cout << ret;
    
}
