#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

unordered_map<string, int> umap;
vector<string> vec;
int iNum;
int pokemonCnt, questionCnt;
string iStr;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> pokemonCnt >>  questionCnt;

	for (int i = 0; i < pokemonCnt; i++) {
		cin >> iStr;
		umap.insert({ iStr, i + 1 });
		vec.push_back(iStr);
	}

	for (int i = 0; i < questionCnt; i++) {
		cin >> iStr;
		char firstChar = iStr.at(0);
		if (firstChar >= 'A' && firstChar <= 'Z') {
			auto item = umap.find(iStr);
			cout << to_string(item->second) << '\n';
		}
		else {
			iNum = stoi(iStr);
			cout << vec.at(iNum - 1) << '\n';
		}
	}
}