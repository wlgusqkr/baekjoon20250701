#include <bits/stdc++.h>
using namespace std;

long long X, Y, init, res = 1e9;

bool check(int mid) {
    if((init) != (long long)(Y+mid) * 100 / (X+mid)) {
        return true;
    }
    return false;
}
int main() {
    
    cin >> X >> Y;
    
    init = (long long)Y * 100 / X;
    
    if(init >= 99) { cout << -1; return 0; }
    
    int l = 1, r = 1e9;
    
    while(l <= r) {
        int mid = (l + r) / 2;
        if(check(mid)) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << res;
    
}
