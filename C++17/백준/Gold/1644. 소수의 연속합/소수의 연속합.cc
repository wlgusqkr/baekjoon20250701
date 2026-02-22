#include <bits/stdc++.h>
using namespace std;

int n, ret, x;
const int max_n = 4000001;
bool che[max_n + 1];

vector<int> era(int mx_n) {
    vector<int> v;
    for(int i = 2; i <= mx_n; i++) {
        if(che[i]) continue;
        for(int j = 2*i; j <= mx_n; j = i + j) {
            che[j] = 1;
        }
    }
    for(int i = 2; i <= mx_n; i++) if(che[i] == 0) v.push_back(i);
    return v;
}


int main() {
    vector<int> a = era(max_n);
    
    cin >> x;
    
    int l = 0, r = 0;

    int p = (int)a.size();
    int sum = 0;

    while( 1 ) {

        // r까지 왔어
        // r == p인 상태야
        if(sum >= x) sum -= a[l++];
        else if(r == p) break;
        else if(sum < x) sum += a[r++];
        if(sum == x) {
            ret++;
        }
        
    }
    cout << ret << '\n';
}
