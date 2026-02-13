#include <bits/stdc++.h>

using namespace std;

int N, from, to, ret;
vector<pair<int, int>> vec;

int main() {
    cin >> N;
    for(int i = 0 ; i < N; i++) {
        int start = 0, end = 0;
        cin >> start >> end;
        vec.push_back({end, start});
    }
    sort(vec.begin(), vec.end());
    
    to = vec[0].first; from = vec[0].second; ret++;
    for(int i = 1 ; i < N; i++) {
        if(vec[i].second < to) continue;
        to = vec[i].first;
        ret++;
    }
    cout << ret;
    
    
}
