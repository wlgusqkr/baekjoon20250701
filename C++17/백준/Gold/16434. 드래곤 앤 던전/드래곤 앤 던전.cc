#include <bits/stdc++.h>
using namespace std;

long long N, H_ATK, res_max = 1e18;
struct Dunjeon {
    long long t; long long a; long long h;
};
vector<Dunjeon> vec;
bool check(long long mid) {
    long long tmp_h_curHP = mid, tmp_h_atk = H_ATK;
    
    for(auto v : vec) {
        if(v.t == 1) { // 몬스터 등장
            long long turns = (v.h + tmp_h_atk - 1) / tmp_h_atk;
            long long damage = (turns - 1) * v.a;
            tmp_h_curHP -= damage;
            if (tmp_h_curHP <= 0) return false;
        } else {
            tmp_h_atk += v.a;
            tmp_h_curHP += v.h;
            if(tmp_h_curHP > mid) tmp_h_curHP = mid;
        }
    }
    return true;
}
int main() {
    cin >> N >> H_ATK;
    long long l = 1, r = 1e18; 
    for(int i = 0 ; i < N; i++) {
        Dunjeon d;
        cin >> d.t >> d.a >> d.h;
        vec.push_back(d);
    }
    
    while(l <= r) {
        long long mid = (l + r) / 2;
        if(check(mid)) {
            res_max = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << res_max;
}
