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
	return a.se < b.se;
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int n; cin >> n;
	vector<pi> times;
	vi lastEnded;

	for ( int i = 0; i < n; i++ ) {
		int s, e; cin >> s >> e;
		times.push_back(make_pair(s, e));
	}

	sort(all(times), Comp);
	lastEnded.push_back(-1);

	for ( auto t: times ) {
		int chk = 0;

		for ( int i = 0; i < lastEnded.size(); i++ ) {
			if ( t.fi >= lastEnded[i] ) {
				lastEnded[i] = t.se;
				chk = 1;
				break;
			}
		}
		if ( !chk ) {
			lastEnded.push_back(t.se);

		}
	}
	cout << lastEnded.size() << endl;

    return 0;
}
