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

	int coins, value, coin;
	vector<int> dp;

	cin >> coins >> value;

	dp.resize(value+1, 0);

	for ( int i = 1; i <= coins; i++ ) {
		cin >> coin;
		for ( int j = coin; j <= value; j++ ) {
			dp[j] += dp[j-coin];
			if ( j == coin ) {
				dp[j]++;
			}
		}
	}

	cout << dp[value] << endl;

    return 0;
}
