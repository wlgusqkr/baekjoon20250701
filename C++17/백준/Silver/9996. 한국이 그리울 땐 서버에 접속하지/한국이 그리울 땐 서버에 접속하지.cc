#include <bits/stdc++.h>
using namespace std;

// *까지 개수
// vector로 
int iNum, firstPatternCount, lastPatternCount;
bool isStar = false;

string pattern, iStr;
vector<string> v;

int main() {
	cin >> iNum;
	cin >> pattern;
	
	for (char c : pattern) {
		if (c == '*') {
			isStar = true;
		}
		else {
			if (isStar == false) {
				firstPatternCount++;
			}
			if (isStar == true) {
				lastPatternCount++;
			}
		}
	}

	for (int c = 0; c < iNum; c++) {
		cin >> iStr;

		bool isFirstPattern = true, isLastPattern = true;
		for (int i = 0; i < firstPatternCount; i++) {
			if (iStr[i] != pattern[i]) {
				isFirstPattern = false;
			}
		}
		for (int i = 0; i < lastPatternCount; i++) {
			if (iStr[(iStr.length() - 1) - i] != pattern[(pattern.length() - 1) - i]) {
				isLastPattern = false;
			}
		}
		if (firstPatternCount + lastPatternCount > iStr.length()) {
			v.push_back("NE");
			continue;
		}
		if (isFirstPattern && isLastPattern) {
			v.push_back("DA");
		}
		else {
			v.push_back("NE");
		}

	}

	for (string st : v) {
		cout << st << '\n';
	}
}