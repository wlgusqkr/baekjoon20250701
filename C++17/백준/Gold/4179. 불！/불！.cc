#include <bits/stdc++.h>
using namespace std;
#define INF 99999
int R, C;

int dy[4] = { -1, 0, +1, 0 };
int dx[4] = { 0, +1, 0, -1 };

char arr[1004][1004];
int person_visited[1004][1004], fire_visited[1004][1004], res;

int main(){
    cin >> R >> C;
    int JX = 0, JY = 0;
    queue<pair<int, int>> que;
    fill(&fire_visited[0][0],&fire_visited[0][0] + 1004*1004, INF);
    
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            scanf(" %c", &arr[i][j]);
            if(arr[i][j] == 'J') {
                JY = i; JX = j;
                person_visited[i][j] = 1;
            } else if (arr[i][j] == 'F') {
                que.push(make_pair(i, j));
                fire_visited[i][j] = 1;
            }
        }
    }
    
    // FIRE
    while(que.size()) {
        
        int y = que.front().first;
        int x = que.front().second;
        que.pop();
        
        for(int i = 0 ; i < 4;i ++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny >= R || ny < 0 || nx >= C || nx < 0) continue;
            if(fire_visited[ny][nx] != INF || arr[ny][nx] == '#') continue;

            fire_visited[ny][nx] = fire_visited[y][x] + 1;
            que.push(make_pair(ny, nx));
        }
    }
    
    //person
    que.push({JY, JX});
    while(que.size()) {
        
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        if(y == R - 1 || x == C - 1 || y == 0 || x == 0) {
            res = person_visited[y][x];
            break;
        }
        
        for(int i = 0 ; i < 4;i ++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny >= R || ny < 0 || nx >= C || nx < 0) continue;
            if(person_visited[ny][nx] || arr[ny][nx] == '#') continue;
            if(fire_visited[ny][nx] <= person_visited[y][x] + 1) continue;
            person_visited[ny][nx] = person_visited[y][x] + 1;
            que.push(make_pair(ny, nx));	
            
        }
    }
    if(res != 0) cout << res << "\n";
    else cout << "IMPOSSIBLE"  << "\n";
}
