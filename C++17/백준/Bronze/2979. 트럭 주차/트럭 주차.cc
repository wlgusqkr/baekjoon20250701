#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int arr[100];

int main() {
	int A, B, C;
	int start, end, sum = 0;

	cin >> A >> B >> C;
	for (int i = 0; i < 3; i++) {
		cin >> start >> end;

		for (int j = start; j < end; j++) {
			arr[j]++;
		}
	}

	for (int i = 0; i < 100; i++) {
		if (arr[i] == 1) {
			sum += A;
		}
		else if (arr[i] == 2) {
			sum += B*2;
		}
		else if (arr[i] == 3) {
			sum += C*3;
		}
	}
	cout << sum;

}