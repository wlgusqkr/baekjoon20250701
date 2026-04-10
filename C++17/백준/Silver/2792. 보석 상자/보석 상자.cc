#include <bits/stdc++.h>
using namespace std;

// 이분탐색
// 질투심을 최소(최적화 문제)
int N, M, arr[300005], res, l = 1, r, mid;

bool check() {
    int tmp = 0;
    for(int i = 0; i < M; i++) {
        tmp = tmp + arr[i]/mid;
        if(arr[i]%mid) {
            tmp++;
        }
    }
    if(tmp > N) return false;
    return true;
}


int main() {
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        cin >> arr[i];
        r = max(r, arr[i]);
    }
    
    while(l <= r) {
        
        mid = (r + l) / 2;
        if(check()) {
            r = mid - 1;
            res = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << res;
}
