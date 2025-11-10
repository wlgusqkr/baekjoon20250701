#include <iostream>
#define _GLIBCXX_HOSTED 1
using namespace std;

int dy[] = { -1, 0, +1, 0 };
int dx[] = { 0, +1, 0, -1 };

bool first = true;
int iY, iX, arr[103][103], visited[103][103], beforeCnt, timeCnt, cnt;
int arrToBeRemoved[103][103];

void dfs(int y, int x) {
    int ny, nx;
    visited[y][x] = 1;
    for(int i = 0 ; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        
        if((ny < 0 || ny >= iY) || (nx >= iX || nx < 0) || arr[y][x] == 1) {
            continue;
        }
        
        if(arr[ny][nx] == 1) {
            arrToBeRemoved[ny][nx] = 1;
            continue;
        }
        
        if(!visited[ny][nx] && arr[ny][nx] == 0) {
            dfs(ny, nx);
        }
        
    }
}

int main(){
    
    cin >> iY >> iX;
    
    for(int i = 0; i < iY; i++) {
        for(int j = 0 ; j < iX; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }
    
    for(int i = 0; i < iY; i++) {
        for(int j = 0; j < iX; j++) {
            if(arr[i][j] == 1)
                cnt++;
        }
    }
    
    while(cnt != 0) {
        timeCnt++; beforeCnt = cnt; cnt = 0;
        
        dfs(0, 0);
        
        for(int i = 0; i < iY; i++) {
            for(int j = 0; j < iX; j++) {
                if(arrToBeRemoved[i][j] == 1){
                    arr[i][j] = 0;
                }
            }
        }
        
        fill(&arrToBeRemoved[0][0],&arrToBeRemoved[0][0] + 103*103, 0);
        fill(&visited[0][0],&visited[0][0] + 103*103, 0);
        
     
        
        for(int i = 0; i < iY; i++) {
            for(int j = 0; j < iX; j++) {
                if(arr[i][j] == 1)
                    cnt++;
            }
            
        }
    }
    cout << timeCnt << endl;

    cout << beforeCnt << endl;
    
    
    
    
}
