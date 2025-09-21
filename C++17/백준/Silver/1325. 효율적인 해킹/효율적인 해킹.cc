#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000; // 넉넉히
vector<int> adj[MAXN + 1];
int N, M;

int vis[MAXN + 1];  // 방문 토큰 저장
int cnt[MAXN + 1];  // 각 시작점에서 도달 가능한 노드 수
int token = 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b; 
        cin >> a >> b;
        // b를 해킹하면 a도 해킹 가능 => 역방향 간선 저장
        adj[b].push_back(a);
    }

    int maxCount = 0;
    for (int s = 1; s <= N; s++) {
        queue<int> q;
        q.push(s);
        vis[s] = token;
        int reach = 0; // s 제외하고 도달한 수만 셀 거면 여기서 +1을 안 함

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (vis[v] != token) {
                    vis[v] = token;
                    q.push(v);
                    reach++;
                }
            }
        }
        cnt[s] = reach;
        if (reach > maxCount) maxCount = reach;
        token++; // 다음 시작점을 위해 토큰 증가
    }

    for (int i = 1; i <= N; i++) {
        if (cnt[i] == maxCount) cout << i << ' ';
    }
    return 0;
}
