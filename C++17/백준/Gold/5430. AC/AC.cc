#include <bits/stdc++.h>
using namespace std;

int T, n;
char arr[100005];
string str, arrStr;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> T;
    for(int i = 0 ; i < T; i++) {
        cin >> str;
        cin >> n;
        cin >> arrStr;
        
        deque<int> dq;
        string numStr = "";
        for (char c : arrStr) {
            if (isdigit(c)) {
                numStr += c;
            } else {
                if (!numStr.empty()) {
                    dq.push_back(stoi(numStr));
                    numStr = "";
                }
            }
        }
        bool isReversed = false, isError = false;
        for(char c : str) {
            if(c == 'R') {
                isReversed = !isReversed;
            } else {
                if(dq.empty()) { isError = true; break;}
                if(isReversed) {
                    dq.pop_back();
                } else {
                    dq.pop_front();
                }
            }
        }
        if(isError) {
            cout << "error";
        } else {
            cout << "[";
            if(isReversed) {
                reverse(dq.begin(), dq.end());
            }
            for(int j = 0; j < dq.size(); j++) {
                if(j == dq.size() - 1) cout << dq[j];
                else cout << dq[j] << ",";
            }
            cout << "]";
        }
        cout <<'\n';
    }
    
}
