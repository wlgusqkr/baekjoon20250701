#include <bits/stdc++.h>

using namespace std;

int iNum;
string iStr;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> iNum;
    
    for(int j = 0 ; j < iNum; j++) {
        
        stack<char> stk;
        
        cin >> iStr;
        
        for(char c : iStr) {
            
            if(!stk.empty() && stk.top() == '(' && c == ')') {
                stk.pop();
            } else {
                stk.push(c);
                continue;
            }
        }
        if(stk.empty()) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }

    
    
    
}
