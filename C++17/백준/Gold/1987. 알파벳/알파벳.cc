#include <bits/stdc++.h>
using namespace std;

int dy[4] = { -1, 0, +1, 0 };
int dx[4] = { 0, +1, 0, -1 };
int R, C, visited[24][24], cnt;

string visitedChar = "";
char arr[24][24];

void DFS(int y, int x) {
    for(int i = 0 ; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny >= R || ny < 0 || nx >= C || nx < 0 || visited[ny][nx]) continue;
        if(visitedChar.find(arr[ny][nx]) != string::npos) continue;
        
        visited[ny][nx] = visited[y][x] + 1;
        visitedChar.push_back(arr[ny][nx]);
        
        DFS(ny, nx);
        
        visited[ny][nx] = 0;
        auto iter = visitedChar.find(arr[ny][nx]);
        visitedChar.erase(iter);
    }
    cnt = max(visited[y][x], cnt);
}

int main() {
    cin >> R >> C;
    
    for(int i = 0; i < R; i++) {
        for(int j = 0 ; j < C; j++) {
            scanf(" %c", &arr[i][j]);
        }
    }
    visitedChar.push_back(arr[0][0]);
    DFS(0, 0);
    cout << cnt + 1<< '\n';
    
}
