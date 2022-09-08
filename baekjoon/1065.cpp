#include <bits/stdc++.h>

#define debug if constexpr (local) std::cout
#define endl '\n'
#define fi first
#define se second
#define all(x) x.begin(),x.end()

#ifdef LOCAL
constexpr bool local = true;
#else
constexpr bool local = false;
#endif

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

/* - GLOBAL VARIABLES ---------------------------- */
 
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */

bool IsHan(int n) {
	int temp = n;
	vector<int> nums;

	if ( n < 10 ) {
		return true;
	}

	while (temp) {
		nums.push_back(temp % 10);
		temp /= 10;
	}
	for (int i = 1, diff = nums[0] - nums[1]; i < nums.size(); i++) {
		if (nums[i-1] - nums[i] != diff) return false;
	}

	return true;
	
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int n, ans = 0;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		if (IsHan(i)) ans++;
	}
	cout << ans << endl;

    return 0;
}
