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

	int vertices, edges; cin >> vertices >> edges;
	vi dist(vertices+1, LINF);
	vector<vi> edge;
	for ( int i = 0; i < edges; i++ ) {
		int from, to, cost; cin >> from >> to >> cost;
		edge.push_back({from, to, cost});
	}

	dist[1] = 0;
	for ( int i = 0; i < vertices; i++ ) {
		for ( auto e: edge ) {
			ll from = e[0];
			ll to = e[1];
			ll cost = e[2];

			if ( dist[from] == LINF ) continue;
			dist[to] = min(dist[to], dist[from]+cost);
		}
	}

	for ( auto e: edge ) {
		ll from = e[0];
		ll to = e[1];
		ll cost = e[2];
		if ( dist[from] == LINF ) continue;
		if ( dist[to] > dist[from]+cost ) {
			cout << -1 << endl;
			return 0;
		}
	}

	for  ( int i = 2; i <= vertices; i++ ) {
		cout << ((dist[i] == LINF) ? -1 : dist[i]) << endl;
	}
    return 0;
}
