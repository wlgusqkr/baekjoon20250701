#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> tasks(n);
    for (int i = 0; i < n; i++) {
        cin >> tasks[i].first >> tasks[i].second; // deadline, cup_noodle
    }

    // 1. 데드라인 기준 오름차순 정렬
    sort(tasks.begin(), tasks.end());

    // 2. 최소 힙 (가장 작은 컵라면 수를 위로)
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++) {
        int deadline = tasks[i].first;
        int noodles = tasks[i].second;

        pq.push(noodles);
        
        // 3. 현재 데드라인보다 과제를 많이 골랐다면, 가장 적게 주는 과제 포기
        if (pq.size() > deadline) {
            pq.pop();
        }
    }

    long long total_noodles = 0;
    while (!pq.empty()) {
        total_noodles += pq.top();
        pq.pop();
    }

    cout << total_noodles << "\n";

    return 0;
}
