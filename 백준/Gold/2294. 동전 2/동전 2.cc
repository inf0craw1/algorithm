#include <iostream>
#include <vector>
#include <set>

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

	int numberOfCoins, objectiveValue, temp;
	set<int> coins;
	vector<vector<int>> dp;

	cin >> numberOfCoins >> objectiveValue;

	for ( int i = 0; i < numberOfCoins; i++ ) {
		cin >> temp;
		coins.insert(temp);
	}

	dp.resize(coins.size()+1, vector<int> (objectiveValue+1, -1));

	int i = 1;
	for ( auto c: coins ) {
		for ( int j = 1; j < c; j++ ) {
			dp[i][j] = dp[i-1][j];
		}
		for ( int j = c; j <= objectiveValue; j++ ) {
			if ( j == c ) {
				dp[i][j] = 1;
				continue;
			}
			if ( dp[i][j-c] == -1 && dp[i-1][j] == -1 ) continue;
			int mini = 2e9;
			if ( dp[i][j-c] != -1 ) mini = dp[i][j-c] + 1;
			if ( dp[i-1][j] != -1 ) mini = min(mini, dp[i-1][j]);
			dp[i][j] = mini;
		}
		i++;
	}

	cout << dp[coins.size()][objectiveValue] << endl;

    return 0;
}
