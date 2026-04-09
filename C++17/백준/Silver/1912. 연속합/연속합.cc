#include <bits/stdc++.h>
using namespace std;

int n, max_res = -1004;

int main() {
    cin >> n;
    int sum = 0;
    for(int i = 0 ; i < n; i++) {
        int a;
        cin >> a;
        sum += a;
        max_res = max(sum, max_res);
        if(sum < 0) sum = 0;
    }
    cout << max_res;
}
