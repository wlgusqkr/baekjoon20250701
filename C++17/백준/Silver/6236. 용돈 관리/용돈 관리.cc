#include <bits/stdc++.h>
using namespace std;

int N, M, arr[100003], res = 1e9;
bool check(int mid) {
    int cnt = 0, account = 0;
    for(int i = 0; i < N; i++) {
        if(account < arr[i]) {
            account = mid;
            account -= arr[i];
            cnt++;
        } else {
            account -= arr[i];
        }
    }
    if(cnt <= M) {
        return true;
    }
    return false;
}
int main() {
    cin >> N >> M;
    
    int l = 1, r = 1e9;
    for(int i = 0 ; i < N; i++) {
        cin >> arr[i];
        l = max(l, arr[i]);
    }
    while(l <= r) {
        int mid = (l + r) / 2;
        if(check(mid)) {
            r = mid - 1;
            res = min(res, mid);
        } else {
            l = mid + 1;
        }
    }
    cout << res;
}
