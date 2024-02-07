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

	int stuff, maxWeight;
	int curWeight, curScore;
	vector<vector<int>> dp;

	cin >> stuff >> maxWeight;

	dp.resize(stuff+1, vector<int> (maxWeight + 1, 0));

	for ( int i = 1; i <= stuff; i++ ) {
		cin >> curWeight >> curScore;

		for ( int j = 1; j <= maxWeight; j++ ) {
			int maxi = dp[i-1][j];
			
			if ( curWeight <= j ) {
				maxi = max(maxi, curScore + dp[i-1][j-curWeight]);
			}
			dp[i][j] = maxi;
		}
	}

	cout << dp[stuff][maxWeight] << endl;

    return 0;
}
