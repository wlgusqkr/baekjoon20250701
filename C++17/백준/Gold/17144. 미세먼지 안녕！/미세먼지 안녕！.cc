#include<bits/stdc++.h>
using namespace std;

int R, C, T, arr[54][54], res;
int airR1, airR2;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, +1, 0, -1 };

void diffuse() {
    int add[54][54] = {};
    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) {
            if(arr[i][j] <= 0) continue;
            int share = arr[i][j] / 5;
            int cnt = 0;
            for(int d = 0; d < 4; d++) {
                int ni = i + dy[d];
                int nj = j + dx[d];
                if(ni < 1 || ni > R || nj < 1 || nj > C) continue;
                if(arr[ni][nj] == -1) continue;
                add[ni][nj] += share;
                cnt++;
            }
            add[i][j] -= share * cnt;
        }
    }
    for(int i = 1; i <= R; i++)
        for(int j = 1; j <= C; j++)
            arr[i][j] += add[i][j];
}

void circulate_top() {
    // 위쪽 공기청정기(airR1, 1): 반시계방향
    // 1) 왼쪽 열: 아래로 당기기
    for(int i = airR1 - 1; i >= 2; i--)
        arr[i][1] = arr[i-1][1];
    // 2) 윗줄: 왼쪽으로 당기기
    for(int j = 1; j <= C - 1; j++)
        arr[1][j] = arr[1][j+1];
    // 3) 오른쪽 열: 위로 당기기 (1행~airR1행)
    for(int i = 1; i <= airR1 - 1; i++)
        arr[i][C] = arr[i+1][C];
    // 4) 공기청정기 행: 오른쪽으로 밀기
    for(int j = C; j >= 3; j--)
        arr[airR1][j] = arr[airR1][j-1];
    arr[airR1][2] = 0;
}

void circulate_bottom() {
    // 아래쪽 공기청정기(airR2, 1): 시계방향
    // 1) 왼쪽 열: 위로 당기기
    for(int i = airR2 + 1; i <= R - 1; i++)
        arr[i][1] = arr[i+1][1];
    // 2) 아랫줄: 왼쪽으로 당기기
    for(int j = 1; j <= C - 1; j++)
        arr[R][j] = arr[R][j+1];
    // 3) 오른쪽 열: 아래로 당기기 (R행~airR2행)
    // 핵심: airR2+1행까지 내려야 함 (airR2행의 C열은 공기청정기가 아님)
    for(int i = R; i >= airR2 + 1; i--)
        arr[i][C] = arr[i-1][C];
    // 4) 공기청정기 행: 오른쪽으로 밀기
    for(int j = C; j >= 3; j--)
        arr[airR2][j] = arr[airR2][j-1];
    arr[airR2][2] = 0;
}

int main(){
    cin >> R >> C >> T;
    for(int i = 1; i <= R; i++)
        for(int j = 1; j <= C; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == -1) {
                if(airR1 == 0) airR1 = i; else airR2 = i;
            }
        }
    
    for(int k = 0; k < T; k++) {
        diffuse();
        circulate_top();
        circulate_bottom();
    }
    
    res = 0;
    for(int i = 1; i <= R; i++)
        for(int j = 1; j <= C; j++)
            if(arr[i][j] > 0) res += arr[i][j];
    cout << res << '\n';
    return 0;
}