#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <bits/stdc++.h>

using namespace std;

string iStr;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    while(true){
        getline(cin, iStr);
        stack<char> stk;
        if( iStr.compare(".") == 0) {
            break;
        }
        for(char c : iStr) {
            if((c == '(' || c == ')' || c == '[' || c == ']')) {
                if(stk.size() == 0) {
                    stk.push(c);
                } else {
                    if(stk.top() == '(' && c == ')') {
                        stk.pop();
                    }
                    else if(stk.top() == '[' && c == ']') {
                        stk.pop();
                    } else {
                        stk.push(c);
                    }
                }
            }
        }
        
        if(stk.size() == 0) {
            cout << "yes" << '\n';
        } else {
            cout << "no" << '\n';
        }
        
    }
    
}
