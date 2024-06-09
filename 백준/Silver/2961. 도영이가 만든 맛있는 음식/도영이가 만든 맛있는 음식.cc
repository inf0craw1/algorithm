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

	int n; cin >> n;
	ll mini = LINF; 
	vector<pi> groceries;

	for ( int i = 0; i < n; i++ ) {
		ll t1, t2;	 cin >> t1 >> t2;
		groceries.push_back(make_pair(t1, t2));
	}

	for ( int i = 1; i < pow(2, n); i++ ) {
		ll curSour = 1, curBitter = 0;
		for ( int cur = i, j = 1; 0 < cur; cur >>= 1, j++ ) {
			if ( cur & 1 ) {
				curSour *= groceries[n - j].fi;
				curBitter += groceries[n - j].se;
			} 
		}
		ll curDiff = curSour - curBitter;
		if ( curDiff < 0 ) curDiff *= -1;
		mini = min(mini, curDiff);
	}

	cout << mini << endl;
    return 0;
}
