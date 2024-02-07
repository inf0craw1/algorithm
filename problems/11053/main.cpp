#include <iostream>
#include <vector>

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

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int n, temp, totalMaxi = 0;
	vector<int> nums, dp;

	cin >> n;

	dp.resize(n + 1, 0);
	nums.push_back(0);

	for ( int i = 0; i < n; i++ ) {
		cin >> temp;
		nums.push_back(temp);
	}

	for (int i = 1; i <= n; i++) {
		int maxi = 0;
		for ( int j = 0; j < i; j++ ) {
			if ( nums[j] < nums[i] ) {
				maxi = max(maxi, dp[j]);
			}
		}
		dp[i] = maxi + 1;
		totalMaxi = max(totalMaxi, maxi + 1);
	}

	cout << totalMaxi << endl;


    return 0;
}
