#include <iostream>
#include <algorithm> 
using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1};
int testCase, M, N, baechuLocationX, baechuLocationY;
int arr[52][52];
int visited[52][52];
int earthwormCount, baechuCount;

void DFS(int y, int x) {
    
    visited[y][x] = 1;
    
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
        if(visited[ny][nx] == 1) continue;
        if(arr[ny][nx] == 0) continue;
        DFS(ny, nx);
    }
    
}

int main(int argc, const char * argv[]) {

    cin >> testCase;
    for(int i = 0 ; i < testCase; i++) {
        fill(&arr[0][0], &arr[51][52], 0);
        fill(&visited[0][0], &visited[52][52], 0);
        earthwormCount = 0;
        cin >> M >> N >> baechuCount;
        for(int j = 0; j < baechuCount; j++) {
            cin >> baechuLocationX >> baechuLocationY;
            arr[baechuLocationY][baechuLocationX] = 1;
        }
        for(int y = 0; y < N; y++) {
            for(int x = 0; x < M; x++) {
                if(visited[y][x] == 1 || arr[y][x] == 0) {
                    continue;
                }
                earthwormCount++;
                DFS(y, x);
            }
        }
        cout << earthwormCount << endl;
    }
    
}
