#include <bits/stdc++.h>
using namespace std;

long long s, e, cnt[100001], n, a[100001];
long long ret;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%lld", a + i);
    }
    while(e < n) {
        if(!cnt[a[e]]) { // 방문하지 않았다면
            cnt[a[e]]++;
            e++;
        } else { // 이미 방문되었다면
            cnt[a[s]]--;
            ret += e - s;
            s++;
        }
    }
    ret = (long long) ((e-s)*((e-s) + 1))/2 + ret;
    cout << ret;
}
