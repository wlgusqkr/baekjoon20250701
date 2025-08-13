#include <iostream>
#include <algorithm>
using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int arr[102][102];
int visited[102][102];
int M, N, K, area, spaceCount;
int areaArr[102];
// 넓이는 ++ 되서 DFS가 호출되었을 때 딱 세면 될듯
// 그리고 visited[i][j] = 1 여기 옆에 넓이++해서 하면 될 듯
// 0,2 4,4 일때 어떻게 배열에 넣지

void DFS(int y, int x) {
    
    visited[y][x] = 1;
    area++;
    
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if(ny < 0 || nx < 0 || ny >= M || nx >= N) continue;
        if(visited[ny][nx] == 1) continue;
        if(arr[ny][nx] == 0) continue;
        
        DFS(ny, nx);
    }
    
}

int main(int argc, const char * argv[]) {
    cin >> M >> N >> K;
    fill(&arr[0][0], &arr[0][0] + 102 * 102, 1);
    for(int i = 0 ; i < K; i++) {
        int y1, x1, y2, x2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j = y1; j < y2; j++) {
            for(int k = x1; k < x2; k++) {
                arr[j][k] = 0;
            }
        }
    }
    
    for(int i = 0 ; i < M; i++) {
        for(int j = 0 ; j < N; j++) {
            if(visited[i][j] == 1 || arr[i][j] == 0) continue;
            area = 0;
            DFS(i, j);
            areaArr[spaceCount] = area;
            spaceCount++;
        }
    }
    cout << spaceCount << '\n';
    sort(areaArr, areaArr + spaceCount);
    for(int i = 0; i < spaceCount; i++) {
        cout << areaArr[i] << " ";
    }
    
}
