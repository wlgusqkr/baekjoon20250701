#include <bits/stdc++.h>
using namespace std;

string str, boom, ret;

int main(){
    cin >> str >> boom;
    
    for(char c : str) {
        ret += c;
        if(ret.size() >= boom.size() && ret.substr(ret.size() - boom.size(), boom.size()) == boom) {
            ret.erase(ret.end() - boom.size(), ret.end());
        }
    }
    if(ret.size()) cout << ret;
    else cout << "FRULA";
    
}

