#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <map>

using namespace std;

int M;
string iStr;
int tmpArr[100];
vector<string> res;
bool customSort(string a, string b) {
    
    if (a.length() > b.length()) {
        return false;
    }
    else if( a.length() < b.length()) {
        return true;
    }
    else {
        return a < b;
    }
}

int main() {
    cin >> M;
    for(int i = 0 ; i < M; i++) {
        cin >> iStr;
        string tmp = "";
        bool bFlag = false;
        for(int j = 0; j < iStr.length(); j++) {
            if((iStr[j] >= 'a') && (iStr[j] <= 'z') && (bFlag == true)) {
                bFlag = false;
                if(tmp[0] == '0') {
                    while(true) {
                        if(tmp[0] != '0' || tmp.length() == 1) {
                            break;
                        } else {
                            tmp = tmp.substr(1);
                        }
                    }
                }
                res.push_back(tmp);
                tmp = "";
            }
            if(iStr[j] >= '0' && iStr[j] <= '9') {
                bFlag = true;
                tmp = tmp + iStr[j];
            }
            
            if((bFlag == true) && j == (iStr.length() - 1)) {
                bFlag = false;
                if(tmp[0] == '0') {
                    while(true) {
                        if(tmp[0] != '0' || tmp.length() == 1) {
                            break;
                        } else {
                            tmp = tmp.substr(1);
                        }
                    }
                }
                res.push_back(tmp);
                tmp = "";
            }
        }
    }
    sort(res.begin(), res.end(), customSort);
    for(auto s: res) {
        cout << s << '\n';
    }
}
