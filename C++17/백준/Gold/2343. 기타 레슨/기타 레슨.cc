#include <bits/stdc++.h>
using namespace std;

int N, M, arr[100003], res = 1e9;

bool check(int mid) {
    int sum = 0, cnt = 0;
    for(int i = N - 1; i >= 0; i--) {
        if(sum + arr[i] > mid) {
            cnt++; sum = 0;
        }
        sum += arr[i];
    }
    if(sum <= mid) {
        cnt++;
    }
    
    return cnt <= M;
    
}

int main() {
    cin >> N >> M;
    
    int l = 1, r = 1e9;
    for(int i = 0 ; i < N; i++) {
        cin >> arr[i];
        l = max(arr[i], l);
        
    }
    
    
    while(l <= r) {
        int mid = (l + r) / 2;
        if(check(mid)) { // cnt가 M보다 작거나 같으면(합격) 최소를 늘릴 수 있다.
            r = mid - 1;
            res = min(mid, res);
        } else { // cnt가 M보다 크면 전체 크기를 키워야댐
            l = mid + 1;
        }
    }
    cout << res;
    
    
}
