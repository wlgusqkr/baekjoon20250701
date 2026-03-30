#include <bits/stdc++.h>
using namespace std;

int N, K, L, headY, headX, t, dir = 1;
int arr[102][102], visited[102][102];
deque<pair<int, int>> vec;
deque<pair<int, int>> _time;
const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, 1, 0, -1 };

int main() {
    
    
    cin >> N >> K;
    
    // 사과
    for(int i = 0 ; i < K; i++) {
        int y = 0, x = 0;
        cin >> y >> x;
        arr[--y][--x] = 3;
    }
    
    cin >> L;
    for(int i = 0 ; i < L; i++) {
        int tmp_time = 0; char c;
        cin >> tmp_time >> c;
        if(c == 'D') _time.push_back({tmp_time, 1});
        else _time.push_back({tmp_time, 3});
    }
    vec.push_back({0, 0});
    
    
    sort(_time.begin(), _time.end());
    
    while(vec.size()) {
        t++;
        int y, x;
        tie(y, x) = vec.front();
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(ny >= N || ny < 0 || nx >= N || nx < 0 || visited[ny][nx]) break;

        // 0이면 뒤에서 빼고 1이면 앞만 0으로 바꿈
        if(!arr[ny][nx]) {
            visited[vec.back().first][vec.back().second] = 0;
            vec.pop_back();
        } else arr[ny][nx] = 0;
        
        visited[ny][nx] = 1;
        vec.push_front({ny, nx});
        
        if( !_time.empty() && t == _time.front().first ) {
            dir = (dir + _time.front().second) % 4;
            _time.pop_front();
        }
        
    }
    cout << t;
    
}
