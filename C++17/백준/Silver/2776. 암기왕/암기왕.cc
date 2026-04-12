#include <bits/stdc++.h>
using namespace std;

int T, N, M, A[1000003], B[1000003], res;

int main() {
    
    cin >> T;
    for(int k = 0 ; k < T; k++) {
        cin >> N;
        
        for(int i = 0 ; i < N; i++) { cin >> A[i]; }
        cin >> M;
        for(int i = 0 ; i < M; i++) { cin >> B[i]; }
        sort(&A[0], &A[0] + N);
        
        for(int i = 0 ; i < M; i++) {
           
            int l = 0, r = N - 1;
            bool flag = 0;
            
            while(l <= r) {
                int mid = (l + r) / 2;
                if(A[mid] < B[i]) {
                    l = mid + 1;
                } else if (A[mid] > B[i]) {
                    r = mid - 1;
                } else {
                    flag = true;
                    break;
                }
            }
            
            if(flag) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
    }

}
