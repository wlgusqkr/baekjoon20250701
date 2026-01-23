#include <bits/stdc++.h>
using namespace std;

int N, K, alpha = 26, cnt, res;

int arr[52];

void combi(int start, vector<int> &vec) {
    if(vec.size() == K) {
        int tmp = 0; cnt = 0;
        for(int j : vec) {
            tmp |= (1 << (int)j);
        }
        for(int j = 0; j < N; j++) {
            if((tmp & arr[j]) == arr[j]) cnt++;
        }
        res = max(cnt, res);
        return;
    }
    for(int i = start + 1; i < alpha; i++) {
        if('a' == i + 'a' || 'c' == i + 'a' || 'i' == i + 'a' || 'n' == i + 'a' || 't' == i + 'a') continue;
        vec.push_back(i);
        combi(i, vec);
        vec.pop_back();
    }
}

int main() {
    
    cin >> N >> K;
    
    for(int i = 0 ; i < N; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < str.size(); j++) {
            arr[i] |= (1 << (((int)(str[j])) - 'a'));
        }
    }
    vector<int> tmp;
    if( K < 5 ) {cout << 0; return 0;}
    tmp.push_back(('a' - 'a'));
    tmp.push_back(('c' - 'a'));
    tmp.push_back(('i' - 'a'));
    tmp.push_back(('n' - 'a'));
    tmp.push_back(('t' - 'a'));
    combi(-1, tmp);
    
    cout << res;
}
