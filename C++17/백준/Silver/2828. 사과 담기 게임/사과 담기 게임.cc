#include <iostream>
using namespace std;

int N, M, J, result;
int appleLocation, chai;

int main(int argc, const char * argv[]) {
    cin >> N >> M >> J;
    int startNumber = 1, endNumber = M;
    
    for(int i = 0 ; i < J; i++) {
        cin >> appleLocation;
        
        if(appleLocation >= startNumber && appleLocation <= endNumber) {
            continue;
        } else if (appleLocation > endNumber) {
            chai = appleLocation - endNumber;
            startNumber += chai; endNumber += chai;
        } else if (appleLocation < startNumber) {
            chai = startNumber - appleLocation;
            startNumber -= chai; endNumber -= chai;
        }
        result += chai;
    }
    cout << result << endl;
}
