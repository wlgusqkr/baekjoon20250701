#include <bits/stdc++.h>
using namespace std;

// 알림을 켠 시점을 생각해야겠다.
//

vector<int> resultVec;
int N, mp, mf, ms, mv, resultP, resultF, resultS, resultV, resultPrice = 999999;
int p[17], f[17], s[17], v[17], c[17];


int main() {
    cin >> N;
    cin >> mp >> mf >> ms >> mv;
    
    for(int i = 0; i < N; i++) {
        cin >> p[i] >> f[i] >> s[i] >> v[i] >> c[i];
    }
    
    for(int i = 0 ; i < (1 << N); i++) {
        vector<int> tmp;
        for(int j = 0; j < N; j++) {
            if(i & (1 << j)) {
                tmp.push_back(j);
            }
        }
        int sumP = 0, sumF = 0, sumS = 0, sumV = 0, sumPrice = 0;
        for(int k : tmp) {
            sumP += p[k]; sumF += f[k]; sumS += s[k]; sumV += v[k]; sumPrice += c[k];
        }
        if(sumP >= mp && sumF >= mf && sumS >= ms && sumV >= mv) {
            if(sumPrice < resultPrice) {
                resultP = sumP; resultF = sumF; resultS = sumS; resultPrice = sumPrice;
                resultVec = tmp;
            } else if(sumPrice == resultPrice) {
                if(tmp < resultVec) {
                    resultVec = tmp;
                }
            }
        }
    }
    
    if(resultPrice == 999999) {
        cout << "-1";
    } else {
        cout << resultPrice << '\n';
        sort(resultVec.begin(), resultVec.end());
        for(int z : resultVec) {
            cout << z + 1 << " ";
        }
    }
}
