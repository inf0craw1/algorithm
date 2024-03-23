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
bool Comp(pi a, pi b) {
	if ( a.se == b.se ) return a.fi < b.fi;
	return a.se > b.se;
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int jewels, bags; cin >> jewels >> bags;
	vector<pi> jewel;
	priority_queue<int> bag;
	ll res = 0;

	for ( int i = 0; i < jewels; i++ ) {
		int weight, value; cin >> weight >> value;
		jewel.push_back(make_pair(weight, value));
	}
	for ( int i = 0; i < bags; i++ ) {
		int b; cin >> b;
		bag.push(b);
	}

	sort(all(jewel), Comp);

	for ( auto j: jewel ) {
		if ( bag.empty() ) break;

		int maxBag = bag.top();
		if ( j.fi > maxBag ) continue;
		res += j.se;
		bag.pop();
	}

	cout << res << endl;

    return 0;
}
