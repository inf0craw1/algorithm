#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

vector<int> increasingNums;

int GetReplacePosition(int target) {
	int s = 0, e = increasingNums.size() - 1;
	int mini = e;

	while ( s <= e ) {
		int mid = (s + e) / 2;
		if ( increasingNums[mid] >= target ) {
			mini = min(mini, mid);
			e = mid - 1;
			continue;
		}
		s = mid + 1;
	}

	return mini;
} 
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);


	int n; cin >> n;
	vector<int> nums;
	int temp;
	for ( int i = 0; i < n; i++ ) {
		cin >> temp;
		nums.push_back(temp);
	}
	increasingNums.push_back(nums[0]);

	for ( int i = 1; i < n; i++ ) {

		if ( increasingNums[increasingNums.size() - 1] < nums[i] ) {
			increasingNums.push_back(nums[i]);
			continue;
		}
		int pos = GetReplacePosition(nums[i]);
		increasingNums[pos] = nums[i];
	}
	cout << increasingNums.size() << endl;
    return 0;
}
