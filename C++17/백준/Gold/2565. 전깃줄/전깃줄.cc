#include <bits/stdc++.h>
using namespace std;


int N, ret_max = -1;
vector<pair<int, int>> vec;
int cnt[500];

int main() {
    
    cin >> N;
    for(int i = 0 ; i < N; i++) {
        int y, x;
        cin >> x >> y;
        vec.push_back({x, y});
    }
    sort(vec.begin(), vec.end());
    
    for(int i = 0 ; i < N; i++) {
        int maxValue = 0;
        for(int j = 0; j < i; j++) {
            if(vec[i].second > vec[j].second && maxValue < cnt[j]) maxValue = cnt[j];
        }
        cnt[i] = maxValue + 1;
        ret_max = max(cnt[i], ret_max);
    }
    cout << N - ret_max;
    
    
    
}
