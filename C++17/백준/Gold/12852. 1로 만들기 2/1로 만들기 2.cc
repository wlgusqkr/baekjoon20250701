#include <bits/stdc++.h>
using namespace std;

int N, dp[1000003];
int from[1000003];

int go(int num) {
    if(num == 1) return 0;
    
    int& ret = dp[num];
    if(ret != 0) return ret;
    
    int tmp0 = 99999999, tmp1 = 99999999, tmp2 = 99999999;
    
    if(num % 3 == 0) {tmp0 = go(num/3);}
    if(num % 2 == 0) {tmp1 = go(num/2);}
    tmp2 = go(num - 1);
    
    int res_min = min({tmp0, tmp1, tmp2});
    
    if(res_min == tmp0) from[num] = num/3;
    if(res_min == tmp1) from[num] = num/2;
    if(res_min == tmp2) from[num] = num - 1;
    
    ret = res_min + 1;
    
    return ret;
}

int main() {
    
    cin >> N;
    cout << go(N) << '\n';
    
    while(N != 0) {
        cout << N << " ";
        N = from[N];
    }
}
