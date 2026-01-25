#include <bits/stdc++.h>
using namespace std;

int N, result, tmp_num;
string tmp_str;
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    
    for(int i = 0 ; i < N; i++) {
        cin >> tmp_str;
        if((!(tmp_str == "all")) && (!(tmp_str == "empty"))) {
            cin >> tmp_num;
        }
        if(tmp_str == "add") {
            if((result & ( 1 << tmp_num )) == 0 ) result |= (1 << tmp_num);
        } else if(tmp_str == "check") {
            if(result & ( 1 << tmp_num )) cout << 1 << '\n';
            else cout << 0 << '\n';
        } else if(tmp_str == "toggle") {
            if((result & ( 1 << tmp_num )) == 0) result |= (1 << tmp_num);
            else result -= (1 << tmp_num);
        } else if(tmp_str == "all") {
            result = (int)pow(2, 21) - 1;
        } else if(tmp_str == "remove") {
            if(result & ( 1 << tmp_num )) result -= (1 << tmp_num);
        } else if(tmp_str == "empty") {
            result = 0;
        }
    }
    
}
