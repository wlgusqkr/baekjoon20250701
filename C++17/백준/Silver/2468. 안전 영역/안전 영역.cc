#include <iostream>
using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int N, safetyZoneCount, resultSafetyZonCount, bigNumber, currentHeight;
int arr[102][102];
int visited[102][102];

void DFS(int y, int x) {
    visited[y][x] = 1;
    
    for(int i = 0 ; i < 4; i++ ){
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if(ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
        if(arr[ny][nx] <= currentHeight) continue;
        if(visited[ny][nx] == 1) continue;
        
        DFS(ny, nx);
    }
}

int main(int argc, const char * argv[]) {
    
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if(arr[i][j] > bigNumber) {
                bigNumber = arr[i][j];
            }
        }
    }
    
    for(int k = 0; k < bigNumber; k++) {
        currentHeight = k;
        fill(&visited[0][0], &visited[0][0] + 102*102, 0);
        safetyZoneCount = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(arr[i][j] <= currentHeight || visited[i][j] == 1) continue;
                safetyZoneCount++;
                DFS(i, j);
            }
        }
        if(safetyZoneCount > resultSafetyZonCount) {
            resultSafetyZonCount = safetyZoneCount;
        }
        
    }
    cout << resultSafetyZonCount << endl;
}
