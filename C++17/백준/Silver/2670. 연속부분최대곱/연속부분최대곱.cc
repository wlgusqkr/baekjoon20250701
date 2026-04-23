#include <bits/stdc++.h>
using namespace std;

int N;
double res_max = -1e9, arr[10004];

int main() {
    cin >> N;
    for(int i = 0 ; i < N ;i++) {
        cin >> arr[i];
    }
    
    for(int i = 0 ; i < N; i++) {
        double tmp = 1.0;
        for(int j = i; j < N; j++) {
            tmp *= arr[j];
            res_max = max(res_max, tmp);
        }
    }
    
    printf("%.3f", res_max);
    
    
}
