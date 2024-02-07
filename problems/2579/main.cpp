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

	int n, temp;
	vector<int> values, dp;

	cin >> n;

	dp.resize(n + 1, 0);
	values.push_back(0);

	for ( int i = 0; i < n; i++ ) {
		cin >> temp;
		values.push_back(temp);
	}

	dp[1] = values[1];
	if ( n == 1 ) { 
		cout << dp[n] << endl;
		return 0;
	}
	dp[2] = values[1] + values[2];
	if ( n == 2 ) {
		cout << dp[n] << endl;
		return 0;
	}

	for (int i = 3; i <= n; i++ ) {
		dp[i] = max(values[i] + dp[i-2], values[i] + values[i-1] + dp[i-3]);
	}
	cout << dp[n] << endl;
    return 0;
}
