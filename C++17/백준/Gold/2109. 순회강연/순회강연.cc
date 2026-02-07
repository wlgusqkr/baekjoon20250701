#include <bits/stdc++.h>
using namespace std;

int n, res;

vector<pair<int, int>> vec;
priority_queue<int> pq;

int main(){
    cin >> n;
    
    for(int i = 0 ; i < n; i++) {
        int d, p; // d는 일 , p는 페이
        cin >> d >> p;
        vec.push_back({ p, d });
    }
    
    sort(vec.begin(), vec.end(), greater<>());
    int j = 0;
    for(int i = 10000; i > 0; i--) {
        while(j < vec.size() && i <= vec[j].first) { pq.push(vec[j++].second); }
        if(!pq.empty()) {
            res += pq.top(); pq.pop();
        }
    }
    cout << res;
    
    
}
