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

	int vertices; cin >> vertices;
	vector<vector<pi>> edges = vector<vector<pi>>(vertices+1);

	for ( int i = 1; i <= vertices; i++ ) {
		int from; cin >> from;

		while ( 1 ) {
			int to; cin >> to;
			if ( to == -1 ) break;
			int cost; cin >> cost;

			edges[from].push_back(make_pair(to, cost));
		}
	}

	for ( auto e: edges ) {
		for ( auto ee: e ) {
			cout << ee.fi << ',' << ee.se << "  ";
		}
		cout << endl;
	}

    return 0;
}
