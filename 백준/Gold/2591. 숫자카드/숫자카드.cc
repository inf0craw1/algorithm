#include <bits/stdc++.h>

#define debug if constexpr (local) std::cout
#define endl '\n'
#define fi first
#define se second
#define INF 0x7fffffff
#define LINF 0x7fffffffffffffff
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

#ifdef LOCAL
constexpr bool local = true;
#else
constexpr bool local = false;
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;

/* - GLOBAL VARIABLES ---------------------------- */
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	string str; cin >> str;

	vi dp(str.size() + 2, 0);

	dp[str.size()] = 1;

	for ( int i = str.size() - 1; i >= 0; i-- ) {
		int res = dp[i+1];
		if ( str[i]-'0' == 0 ) continue;

		if ( i == str.size() - 1 ) {
			dp[i] = 1;
			continue;
		}

		if ( (str[i]-'0') * 10 + (str[i+1]-'0') <= 34 ) res += dp[i+2];

		dp[i] = res;
	}
	cout << dp[0] << endl;

    return 0;
}
