#include <bits/stdc++.h>
using namespace std;

int N, M, cnt, temp;
map<int, int> _map;
int main() {
    
    cin >> N >> M;
    
    for(int i = 0; i < N; i++) {
        cin >> temp; _map[temp]++;
    }
    for(int i = 0; i < M; i++) {
        cin >> temp; _map[temp]++;
    }
    for(auto it : _map) {
        if(it.second == 1)cnt++;
    }
    cout << cnt;
    
}
