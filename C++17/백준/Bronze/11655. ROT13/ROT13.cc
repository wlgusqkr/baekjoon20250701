#include <bits/stdc++.h>
using namespace std;
string iStr, ret;

int main() {

	getline(cin, iStr);

	for (int i = 0; i < iStr.length(); i++) {
		char& word = iStr[i];
		if (word >= 'a' && word <= 'z') {
			word = (((word - 'a') + 13) % 26) + 'a';
		}
		else if (word >= 'A' && word <= 'Z') {
			word = (((word - 'A') + 13) % 26) + 'A';
		}
	}
	cout << iStr;
}