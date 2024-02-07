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
bool IsSafe(int i, int j) {
	if ( i < 0 || j < 0 ) return 0;
	if ( i < j ) return 0;
	return 1;
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int n, temp, totalMaxi = 0;
	vector<vector<int>> m, dp;

	cin >> n;

	dp.resize(n, vector<int> (n, 0));

	for ( int i = 0; i < n; i++ ) {
		vector<int> tempRow;
		for ( int j = 0; j <= i; j++ ) {
			cin >> temp;
			tempRow.push_back(temp);
		}
		m.push_back(tempRow);
	}

	for ( int i = 0; i < n; i ++ ) {
		for ( int j = 0; j <= i; j++ ) {
			int maxi = 0;
			if ( IsSafe(i-1, j-1) ) {
				maxi = max(maxi, dp[i-1][j-1]);
			}
			if ( IsSafe(i-1, j) ) {
				maxi = max(maxi, dp[i-1][j]);
			}
			dp[i][j] = maxi + m[i][j];
		}
	}

	for ( int i = 0; i < n; i++ ) {
		totalMaxi = max(totalMaxi, dp[n-1][i]);
	}

	cout << totalMaxi << endl;

    return 0;
}
