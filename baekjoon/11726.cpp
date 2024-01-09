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

	int target;

	cin >> target;

	vector<vector<ull>> dp(2, vector<ull> (target, 0));

	dp[0][0] = 1;

	for ( int i = 1; i < target; i++ ) {
		dp[0][i] = dp[0][i-1] + dp[1][i-1];
		dp[1][i] = dp[0][i-1];

	}

	for(int i = 0; i < target; i++) {
		cout << dp[0][i] << ' ' << dp[1][i] << endl;
	}


	cout << dp[0][target-1] + dp[1][target-1] << endl;




    return 0;
}
