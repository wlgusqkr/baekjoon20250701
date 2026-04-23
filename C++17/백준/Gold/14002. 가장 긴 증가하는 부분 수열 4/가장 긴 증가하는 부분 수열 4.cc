#include <bits/stdc++.h>
using namespace std;

int n, arr[1002], cnt[1002], ret, retIdx;
int to[1002];
stack<int> stk;
int main() {
    
    fill(to, to+ 1002 , -1);
    cin >> n;
    
    for(int i = 0 ; i < n; i++) {
        cin >> arr[i];
    }
    for(int i = 0 ; i < n; i++) {
        int maxValue = 0;
        for(int j = 0 ; j < i; j++) {
            if(arr[j] < arr[i] && maxValue < cnt[j]) {maxValue = cnt[j]; to[i] = j;}
        }
        cnt[i] = maxValue + 1;
        if(ret < cnt[i]) {
            ret = cnt[i];
            retIdx = i;
        }
    }
    cout << ret << '\n';
    while(retIdx != -1) {
        stk.push(arr[retIdx]);
        retIdx = to[retIdx];
    }
    while(!stk.empty()) {
        cout << stk.top() << " "; stk.pop();
    }
}
