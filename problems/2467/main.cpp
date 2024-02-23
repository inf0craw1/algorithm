#include <bits/stdc++.h>

#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

/* - GLOBAL VARIABLES ---------------------------- */
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

	int n, mini = 2e9; cin >> n;
	vector<int> nums(n);
	for ( auto &x: nums ) cin >> x;

	int s = 0, e = n - 1;
	int saveS = 0, saveE = 0;

	while (s < e)  {
		int sum = nums[s] + nums[e];
		if ( mini > abs(sum) ) {
			mini = abs(sum);
			saveS = nums[s];
			saveE = nums[e];
			if ( sum == 0 ) break;
		}
		if ( sum > 0 ) {
			e--;
			continue;
		}
		s++;
	}

	cout << saveS << ' ' << saveE << endl; 

    return 0;
}
