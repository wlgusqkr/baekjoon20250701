#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;


const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, +1, 0, -1};

int arr[9][9], N, M, visited[9][9], tmp[9][9], areaCount;
vector<pair<int,int>> vec;

void dfs(int y, int x) {
    if(x >= M || x < 0 || y >= N || y < 0 || visited[y][x] == 1 || tmp[y][x] == 1) {
        return;
    }
    
    visited[y][x] = 1;
    tmp[y][x] = 2;
    
    for(int i = 0 ; i < 4; i++) {
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        
        dfs(ny, nx);
    }
}

int main() {
    
    fill(&arr[0][0], &arr[0][0] + 9*9, -1);
    
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf("%1d", &arr[i][j]);
            if(arr[i][j] == 2) {
                vec.push_back(make_pair(i, j));
            }
        }
    }
    
    for(int i = 0 ; i < N*M; i++) {
        for(int j = i + 1 ; j < N*M; j++) {
            for(int k = j + 1 ; k < N*M; k++) {
                if((arr[i/M][i%M] == 0)&&(arr[j/M][j%M] == 0)&&(arr[k/M][k%M] == 0)) {
                    
                    int tmpCount = 0;
                    fill(&tmp[0][0], &tmp[0][0] + 9*9, 0);
                    fill(&visited[0][0], &visited[0][0] + 9*9, 0);
                    
                    memcpy(tmp,arr,sizeof(arr));
                    
                    tmp[i/M][i%M] = 1; tmp[j/M][j%M] = 1; tmp[k/M][k%M] = 1;
                    
                    for(auto pai : vec) {
                        dfs(pai.first, pai.second);
                    }
                    
                    for(int z = 0 ; z < N; z++) {
                        for(int u = 0; u < M; u++) {
                            if(tmp[z][u] == 0) {
                                tmpCount++;
                            }
                        }
                    }
                    areaCount = max(tmpCount, areaCount);
                } else {
                    continue;
                }
            }
        }
    }
    
    cout << areaCount << '\n';
    
}
