#include <bits/stdc++.h>
using namespace std;

int N, K, arr[1400], n = 1;
vector<int> result[11];

// 처음에 z는 3
// 1넣고 3 +
void go(int start, int cnt, int chng) {
    
    if(cnt == 0) {
        return;
    }
    chng++;
    result[chng].push_back(arr[start - cnt]);
    result[chng].push_back(arr[start + cnt]);
    go(start - cnt, cnt/2, chng);
    go(start + cnt, cnt/2, chng);
    
}
int main() {
    cin >> K;
    n = pow(2, K) - 1;
    for(int i = 0 ; i < n; i++) {
        cin >> arr[i];
    }
    
    int cnt = 0;
    int chng = 0;
    
    int start = n/2;
    result[chng].push_back(arr[start]);
    
    go(start, ((n+1)/2)/2, chng);
    
    for(int i = 0 ; i < K; i++) {
        for(int j : result[i]) {
            cout << j << " ";
        }
        cout << '\n';
    }
    
    
}
