#include <bits/stdc++.h>
using namespace std;



const int MAX = 100003;
int N, K;
int visited[MAX], cnt[MAX];

int main(){
    cin >> N >> K;
    
    queue<int> que;
    que.push(N);
    visited[N] = 1;
    cnt[N] = 1;

    while(que.size()) {

        int now = que.front();
        que.pop();
        
        for(int next : { now - 1, now + 1, now * 2}) {
            if(next >= MAX || next < 0) continue;
            if(!visited[next]) {
                visited[next] = visited[now] + 1;
                que.push(next);
                cnt[next] = cnt[now];
            } else if (visited[next] == visited[now] + 1) {
                cnt[next] += cnt[now];
            }
        }
        
    }
    
    cout << visited[K] - 1 << '\n';
    cout << cnt[K] << '\n';
}
