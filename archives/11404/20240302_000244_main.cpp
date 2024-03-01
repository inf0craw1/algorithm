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
	int edges; cin >> edges;
	vector<vi> graph(vertices+1, vi (vertices+1, INF));

	for ( int i = 1; i <= vertices; i++ ) {
		graph[i][i] = 0;
	}


	for ( int i = 0; i < edges; i++ ) {
		ll from, to, cost; cin >> from >> to >> cost;

		graph[from][to] = min(graph[from][to], cost);
	}

	for ( int i = 1; i <= vertices; i++ ) {
		for ( int j = 1; j <= vertices; j++ ) {
			for ( int k = 1; k <= vertices; k++ ) {
				graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
			}
		}
	}

	for ( int i = 1; i <= vertices; i++ ) {
		for ( int j = 1; j <= vertices; j++ ) {
			cout << ( graph[i][j] == INF ? 0 : graph[i][j] ) << ' ';
		}
		cout << endl;
	}
    return 0;
}
