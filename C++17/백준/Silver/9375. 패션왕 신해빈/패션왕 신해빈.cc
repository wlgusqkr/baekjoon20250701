#include <bits/stdc++.h>
using namespace std;

int n, t;
int main() {
	string type, name;
	cin >> t;
	for (int i = 0; i < t; i++) {
		map<string, int> dic;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> name >> type;
			dic[type]++;
		}
		int ret = 1;
		for (auto c : dic) {
			ret *= (c.second + 1);
		}
		ret--;
		cout << ret << '\n';
	}
}