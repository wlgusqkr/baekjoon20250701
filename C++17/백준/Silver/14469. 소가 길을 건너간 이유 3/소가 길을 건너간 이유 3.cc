#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int cnt, res;

int main() {
    cin >> cnt;
    vector<pair<int, int>> vec(cnt);
    for(int i = 0 ; i < cnt ; i++) {
        cin >> vec[i].first >> vec[i].second; // 도착 시간, 검문 시간
    }
    sort(vec.begin(), vec.end());
    
    
    for(int i = 0 ; i < vec.size(); i++) {
        if(res >= vec[i].first) {
            res += vec[i].second;
        } else {
            res = vec[i].first + vec[i].second;
        }
        
    }
    cout << res;
}
