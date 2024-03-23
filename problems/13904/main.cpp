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
	if ( a.fi == b.fi ) return a.se > b.se;
	return a.fi < b.fi;
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int assignment; cin >> assignment;
	vector<pi> assignments; 

	for ( int i = 0; i < assignment; i++ ) {
		int remainDays, score; cin >> remainDays >> score;

		assignments.push_back(make_pair(remainDays, score));
	}

	sort(all(assignments), Comp);

	for ( auto a: assignments ) {
		cout << a.fi << ' ' << a.se << endl;
	}

    return 0;
}
