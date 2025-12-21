#include <bits/stdc++.h>

using namespace std;

int M, N;
int dy[4] = { -1, 0, +1, 0 };
int dx[4] = { 0, +1, 0, -1 };

int visited[52][52], arr[52][52], tmpArr[52][52];


// 최단거리 -> BFS
// 시간 제한 1억번

int BFS(int startY, int startX) {
    
    queue<pair<int, int>> que;
    que.push(make_pair(startY, startX));
    
    arr[startY][startX] = 1;
    
    while(que.size() != 0){
        int y = que.front().first;
        int x = que.front().second;
        
        que.pop();
        // n^2(정점) + 4n^2(간선) = 5n^2
        // 5n^2 X n^2 = 5 n^4
        
        // 50 2500 125000 6250000
        
        for(int i = 0 ; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny >= N || ny < 0 || nx >= M || nx < 0) continue;
            if(arr[ny][nx] == -1 || arr[ny][nx] > 0) continue;
            
            arr[ny][nx] = arr[y][x] + 1;
            que.push(make_pair(ny, nx));
        }
        
    }
    
    int maxDistance = 0;
    
    for(int i = 0 ; i < N; i++) {
        for(int j = 0; j < M; j++) {
            maxDistance = max(maxDistance, arr[i][j]);
        }
    }
    
    return maxDistance;
    
}

int main(){
    
    cin >> N >> M;
    
    int resultDistance = 0;
    
    for(int i = 0 ; i < N; i++) {
        for(int j = 0 ; j < M; j++) {
            char tmpChar;
            scanf(" %c", &tmpChar);
            if(tmpChar == 'L') {
                arr[i][j] = 0;
            } else {
                arr[i][j] = -1;
            }
        }
    }

    for(int i = 0 ; i < N; i++) {
        for(int j = 0 ; j < M; j++) {
            tmpArr[i][j] = arr[i][j];
        }
    }
    
  
    for(int i = 0 ; i < N; i++) {
        for(int j = 0 ; j < M; j++) {
            
            // 초기화
            if(arr[i][j] == -1) continue;
            fill(&visited[0][0], &visited[0][0] + 52*52, 0);
            
            for(int k = 0 ; k < N; k++) {
                for(int z = 0 ; z < M; z++) {
                    arr[k][z] = tmpArr[k][z];
                }
            }
            
            resultDistance = max(resultDistance, BFS(i, j));
            
        }
    }
    
    cout << resultDistance - 1 << '\n';
    
    
    
}
    

