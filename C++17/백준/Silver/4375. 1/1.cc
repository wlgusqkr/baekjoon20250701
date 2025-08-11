#include <iostream>
using namespace std;


int n;
int main(int argc, const char * argv[]) {
    while(cin >> n) {
        long long testNum = 1;
        int digit = 1;
        for(int i = 0; true ;i++) {
            if(testNum % n == 0) {
                cout << digit << '\n';
                break;
            }
            
            testNum = (testNum * 10 + 1) % n;
            digit++;
        }
    }
}
