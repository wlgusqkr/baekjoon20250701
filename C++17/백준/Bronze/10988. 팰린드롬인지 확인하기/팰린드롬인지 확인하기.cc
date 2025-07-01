#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main() {
	string iStr;
	int strLength;
	bool bFlag;

	getline(cin, iStr);
	strLength = iStr.length();
	bFlag = true;
	for (int i = 0; i < (strLength / 2); i++) {
		if (iStr[i] != iStr[strLength - (i + 1)]) {
			bFlag = false;
		}
	}
	if (bFlag) {
		cout << 1;
	}
	else {
		cout << 0;
	}
}