#include <bits/stdc++.h>
using namespace std;
const int INF = 9999;

int N, dp[64][64][64], visited[64][64][64], arr[3];

int attack[6][3] = {
    { 9, 3, 1 },
    { 9, 1, 3 },
    { 3, 1, 9 },
    { 3, 9, 1 },
    { 1, 3, 9 },
    { 1, 9, 3 },
};

struct A {
    int a, b, c;
};
queue<A> que;
int go(int a, int b, int c){
    visited[a][b][c] = 1;
    que.push({a, b, c});
    
    while(que.size()) {
        int a = que.front().a;
        int b = que.front().b;
        int c = que.front().c;
        que.pop();
        if(visited[0][0][0] != 0) break;
        for(int i = 0 ; i < 6; i++) {
            int na = max(0, a - attack[i][0]);
            int nb = max(0, b - attack[i][1]);
            int nc = max(0, c - attack[i][2]);
            
            if(visited[na][nb][nc]) continue;
            visited[na][nb][nc] = visited[a][b][c] + 1;
            que.push({na, nb, nc});
        }
    }
    
    return visited[0][0][0];
}
int main(){
    cin >> N;

    for(int i = 0 ; i < N; i++) {
        cin >> arr[i];
    }
    
    cout << go(arr[0], arr[1], arr[2]) - 1;

}
