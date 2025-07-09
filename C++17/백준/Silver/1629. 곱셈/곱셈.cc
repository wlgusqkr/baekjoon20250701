#include <bits/stdc++.h>
using namespace std;

int A, B, C, x, y, z;
int BSum, idx = 1, result = 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long A, B, C;
    cin >> A >> B >> C;

    long long result = 1;
    A %= C;

    while (B > 0) {
        if (B % 2 == 1) {
            result = (result * A) % C;
        }

        A = (A * A) % C;

        B /= 2;
    }

    cout << result;

    return 0;
}