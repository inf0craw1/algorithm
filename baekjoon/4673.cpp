#include <bits/stdc++.h>

using namespce std;

int main() {
	vector<int> self_numbers = {1, 3, 5, 7, 9, 20, 31, 42, 53, 64, 75, 86, 97};

	while(self_numbers[self_numbers.size() - 1] <= 10000) {
		int last = self_numbers[self_nubmers.size() - 1];
		int temp = last;
		int new = last;
		
		while(temp) {
			new += temp % 10;
			temp /= 10;
		}
		self_numbers.push_back(new);
	}
	for(int i = 0; i < self_nubmers.size(); i++) {
		cout << self_numbers[i] << ' ';
	}
	return 0;
}
