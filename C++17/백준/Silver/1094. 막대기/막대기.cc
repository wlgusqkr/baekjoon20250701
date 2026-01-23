#include <bits/stdc++.h>
using namespace std;

int num, cnt;
int main() {
    
    cin >> num;
    
    for(int i = 0 ; i < 8; i++) {
        if(num & (1 << i)) {
            cnt++;
        }
    }
    cout << cnt;
    
}
