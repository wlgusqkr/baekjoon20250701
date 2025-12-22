#include <bits/stdc++.h>
using namespace std;

int N, L, R, result_count;

int dy[4] = { -1, 0, +1, 0 };
int dx[4] = { 0, +1, 0, -1 };

int arr[52][52], visited[52][52];
vector<vector<pair<int, int>>> result_vec;

void DFS(int y, int x, vector<pair<int, int>>& vec) {
    
    if(visited[y][x] == 1) return;
    
    visited[y][x] = 1;
    
    
    for(int i = 0 ; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if(ny >= N || ny < 0 || nx >= N || nx < 0) continue;
        if(visited[ny][nx] == 1) continue;
        if(abs(arr[ny][nx] - arr[y][x]) >= L && abs(arr[ny][nx] - arr[y][x]) <= R) {
            vec.push_back(make_pair(ny, nx));
            DFS(ny, nx, vec);
        }
    }
    
}

int main(){
    
    cin >> N >> L >> R;
    
    // 초기화
    for(int i = 0 ; i < N; i++) {
        for(int j = 0 ; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    
    while(true) {
        
        result_vec.clear();
        fill(&visited[0][0], &visited[0][0] + 52 * 52, 0);
        
        for(int i = 0 ; i < N; i++) {
            for(int j = 0 ; j < N; j++) {
                vector<pair<int, int>> tmp_vec;
                tmp_vec.push_back(make_pair(i, j));
                DFS(i, j, tmp_vec);
                if(tmp_vec.size() >= 2) {
                    result_vec.push_back(tmp_vec);
                }
            }
        }
        
        if(result_vec.size() == 0) break;
        

        for(int i = 0 ; i < result_vec.size(); i++) {
            
            int sum = 0, quotient = 0;
            
            for(int j = 0 ; j < result_vec[i].size(); j++) {
                sum += arr[result_vec[i][j].first][result_vec[i][j].second];
            }
            
            quotient = sum / result_vec[i].size();
            
            for(int j = 0 ; j < result_vec[i].size(); j++) {
                arr[result_vec[i][j].first][result_vec[i][j].second] = quotient;
            }
            
        }
        
        result_count++;
        
    }
    
    cout << result_count;
}
