#include <iostream>
using namespace std;

void sub(int y1, int x1, int y2, int x2, string& str);
int arr[70][70];

string check(int y1, int x1, int y2, int x2) {
    int halfN = (y2 - y1) / 2;
    string str;
    
    sub(y1, x1, y1 + halfN, x1 + halfN, str);
    sub(y1, x1 + halfN, y1 + halfN, x2, str);
    sub(y1 + halfN, x1, y2, x1 + halfN, str);
    sub(y1 + halfN, x1 + halfN, y2, x2, str);
    
    return "(" + str + ")";
    
}

void sub(int y1, int x1, int y2, int x2, string& str) {
    bool hasZero, hasOne;
    
    hasZero = false;
    hasOne = false;
    for(int i = y1 ; i < y2; i++) {
        for(int j = x1 ; j < x2; j++) {
            if(arr[i][j] == 1) hasOne = true;
            if(arr[i][j] == 0) hasZero = true;
        }
    }
    if(hasZero == true && hasOne == true) {
        str += check(y1, x1, y2, x2);
    } else if (hasZero == true) {
        str += "0";
    } else if (hasOne == true) {
        str += "1";
    }
}

int main(int argc, const char * argv[]) {
    int inputNum;
    string result;
    cin >> inputNum;
    bool hasZero, hasOne;
    for(int i = 0; i < inputNum; i++) {
        for(int j = 0 ; j < inputNum; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }
    
    hasZero = false;
    hasOne = false;
    for(int i = 0 ; i < inputNum; i++) {
        for(int j = 0 ; j < inputNum; j++) {
            if(arr[i][j] == 1) hasOne = true;
            if(arr[i][j] == 0) hasZero = true;
        }
    }
    
    if(hasZero == true && hasOne == true) {
        result += check(0, 0, inputNum, inputNum);
    } else if (hasZero == true) {
        result += "0";
    } else if (hasOne == true) {
        result += "1";
    }
    cout << result << '\n';
}
