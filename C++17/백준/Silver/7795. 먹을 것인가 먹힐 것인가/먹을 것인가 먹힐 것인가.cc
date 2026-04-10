#include <bits/stdc++.h>
using namespace std;

int N, M, T, A[20005], B[20005];
bool check(int i, int mid) {
    return B[mid] < A[i];
}

int main() {
    cin >> T;
    for(int i = 0 ; i < T; i++) {
        
        cin >> N >> M;
        for(int j = 0 ; j < N; j++) {
            cin >> A[j];
        }
        sort(&A[0], &A[0] + N);
        for(int j = 0 ; j < M; j++) {
            cin >> B[j];
        }
        sort(&B[0], &B[0] + M);
        int res = 0;
        for(int j = 0 ; j < N; j++) {
            int l = 0, r = M - 1;
            int tmp_max = 0;
            while(l <= r) {
                int mid = (l + r) / 2;
                
                if(check(j, mid)) {
                    l = mid + 1;
                    tmp_max = max(tmp_max, mid + 1);
                } else {
                    r = mid - 1;
                }
            }
            res += tmp_max;
        }
        cout << res << '\n';
    }
    
}
