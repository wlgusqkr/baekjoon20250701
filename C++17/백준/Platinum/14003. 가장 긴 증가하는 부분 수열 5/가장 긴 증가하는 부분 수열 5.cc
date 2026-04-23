#include <bits/stdc++.h>
using namespace std;

int n, lis[1000003], num, len;

pair<int, int> ans[1000003];
const int INF = 1e9 + 4;
stack<int> stk;

int main() {
    cin >> n;
    
    fill(&lis[0], &lis[0] + 1000003, INF);
    for(int i = 0 ; i < n; i++) {
        cin >> num;
        auto lowerPos = lower_bound(lis, lis + len, num);
        int _pos = (int)(lower_bound(lis, lis + len, num) - lis);
        if(*lowerPos == INF) len++;
        *lowerPos = num;
        ans[i].first = _pos;
        ans[i].second = num;
    }
    
    cout << len << '\n';
    for(int i = n - 1; i >= 0; i--) {
        if(ans[i].first == len - 1) {
            stk.push(ans[i].second); len--;
        }
    }
    
    while(!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
    
    
    
    
}
