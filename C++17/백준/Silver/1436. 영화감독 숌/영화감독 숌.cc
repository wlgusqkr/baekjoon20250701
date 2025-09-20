#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int iNum;
    cin >> iNum;
    
    for(int i = 0;;i++) {
        if(to_string(i).find("666") != string::npos) {
            iNum--;
        }
        if(iNum == 0) {
            cout << i;
            return 0;
        }
    }

    
    
    
}
