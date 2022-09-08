#include <bits/stdc++.h>

using namespace std;

int d(int n) {
	int temp = n, res = n;

	while(temp) {
		res += temp % 10;
		temp /= 10;
	}

	return res;
}

int main() {
	int numbers[10001] = {0};

	for (int i = 1; i < 10000; i++) {
		int temp = d(i);

		while ( temp <= 10000 && !numbers[temp]) {
			numbers[temp] = true;
			temp = d(temp);
		}
	}

	for (int i = 1; i <= 10000; i++) {
		if (!numbers[i]) {
			cout << i << endl;
		}
	}
	return 0;
}
