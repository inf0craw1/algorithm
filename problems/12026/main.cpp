#include <bits/stdc++.h>

#define debug if constexpr (local) std::cout
#define endl '\n'
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

#ifdef LOCAL
constexpr bool local = true;
#else
constexpr bool local = false;
#endif

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
typedef unsigned long long ull;

/* - GLOBAL VARIABLES ---------------------------- */
int pos = 0, len, res = inf;
string road;
vector<int> dp;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	cin >> len >> road;
	dp.resize(len, inf);

	dp[0] = 0;

	for ( int i = 1; i < len; i++ ) {
		int mini = inf;
		char beforeRoad;
		if ( road[i] == 'B' ) {
			beforeRoad = 'J';
		} else if ( road[i] == 'O' ) {
			beforeRoad = 'B';
		} else {
			beforeRoad = 'O';
		}
		for ( int j = 0; j < i; j++ ) {
			if ( road[j] == beforeRoad ) {
				mini = min(mini, dp[j] + (int)pow(i - j, 2));
			}
		}
		dp[i] = mini;
	}
	if ( dp[len-1] == inf) {
		cout << -1 << endl;
		return 0;
	}
	cout << dp[len-1] << endl;
    return 0;
}
