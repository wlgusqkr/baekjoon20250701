#include <bits/stdc++.h>

using namespace std;

int N, K;
long long ret;
vector<pair<int, int>> jewel_info;
vector<int> bag_info;
priority_queue<int> pq;

int main() {
    
    cin >> N >> K; // 보석의 수, 가방의 수
    for(int i = 0; i < N; i++) {
        int M = 0, V = 0;
        cin >> M >> V;
        jewel_info.push_back({ M, V });
    }
    
    for(int i = 0; i < K; i++) {
        int C;
        cin >> C;
        bag_info.push_back(C);
    }
    sort(bag_info.begin(), bag_info.end());
    sort(jewel_info.begin(), jewel_info.end());
    
    int j = 0;
    for(int i = 0; i < K; i++) {
        while(j < N && jewel_info[j].first <= bag_info[i]) pq.push(jewel_info[j++].second);
        if(pq.size()) {
            ret += pq.top(); pq.pop();
        }
    }
    cout << ret;
    
    
    
    
    
}
