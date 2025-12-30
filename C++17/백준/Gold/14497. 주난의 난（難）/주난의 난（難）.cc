#include <bits/stdc++.h>
using namespace std;

int dy[4] = { -1, 0 , 1, 0 };
int dx[4] = { 0, +1, 0, -1 };
int N, M, x_1, x_2, y_2, y_1, cnt;

char arr[304][304];
int visited[304][304];
bool ok = false;

int main() {
    
    cin >> N >> M;
    cin >> y_1 >> x_1 >> y_2 >> x_2;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0 ; j < M; j++) {
            scanf(" %c", &arr[i][j]);
        }
    }
    
    
    while(true) {

        cnt++;
        queue<pair<int, int>> que;
        que.push({y_1 - 1, x_1 - 1});
        fill(&visited[0][0], &visited[0][0] + 304 * 304, 0);
        visited[y_1 - 1][x_1 - 1] = 1;
        
        while(que.size()) {
            int y, x;
            tie(y, x) = que.front();
            que.pop();
            
            for(int i = 0 ; i < 4; i++) {
                
                int ny = y + dy[i];
                int nx = x + dx[i];
                
                if(ny >= N || ny < 0 || nx >= M || nx < 0) continue;
                if(visited[ny][nx]) continue;
                if(arr[ny][nx] == '#') {
                    cout << cnt<< '\n';
                    exit(0);
                }
                visited[ny][nx] = 1;
                if(arr[ny][nx] == '1') {
                    arr[ny][nx] = '0';
                } else {
                    que.push({ ny, nx });
                }
            }
        }
        
    }

    
}
