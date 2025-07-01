#include <bits/stdc++.h>
using namespace std;

int arr[200];
string iStr;

int main() {
	cin >> iStr;
	for (char c : iStr) {
		arr[(int)c]++;
	}
	for (int i = (int)'a'; i <= (int)'z'; i++) {
		cout << arr[i] << " ";
	}
}