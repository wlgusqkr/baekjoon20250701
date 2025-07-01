#include <bits/stdc++.h>
using namespace std;

string iStr, reverseStr;
bool isPalindrome = true;
int main() {
	cin >> iStr;
	reverseStr = iStr;
	reverse(reverseStr.begin(), reverseStr.end());

	for (int i = 0; i < iStr.length(); i++) {
		if (iStr[i] != reverseStr[i]) {
			isPalindrome = false;
		}
	}

	if (isPalindrome) {
		cout << '1';
	}
	else {
		cout << '0';
	}
}
