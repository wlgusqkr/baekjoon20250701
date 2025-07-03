#include <bits/stdc++.h>
using namespace std;

int iTempDayNum, iSeqDayNum, iTemp[100001], pSum[100004];
int ret = -100000004;
int main() {
	cin >> iTempDayNum >> iSeqDayNum;
	for (int i = 1; i <= iTempDayNum; i++) {
		cin >> iTemp[i];
	}

	for (int i = 1; i <= iTempDayNum; i++) {
		pSum[i] = pSum[i - 1] + iTemp[i];
	}
	for (int i = 0; i < iTempDayNum - iSeqDayNum + 1; i++) {
		ret = max(ret, pSum[i + iSeqDayNum] - pSum[i]);
	}
	cout << ret << '\n';


}