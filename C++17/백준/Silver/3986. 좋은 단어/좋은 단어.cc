#include <bits/stdc++.h>
using namespace std;

string iStr;
int N,result;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	cin.ignore();

	for (int i = 0; i < N; i++) {
		stack<char> myStack;
		getline(cin, iStr);
		for (char c : iStr) {
			if (myStack.empty() || myStack.top() != c) {
				myStack.push(c);
			}
			else {
				myStack.pop();
				continue;
			}
		}

		if (myStack.size() == 0) {
			result++;
		}
	}
	cout << result;
}