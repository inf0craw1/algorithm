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
	int startAt; cin >> startAt;
	vector<vector<pi>> graph(vertices+1);
	vi dist(vertices+1, INF);

	for ( int i = 0; i < edges; i++ ) {
		int from, to, cost; cin >> from >> to >> cost;
		graph[from].push_back(make_pair(to, cost));
	}

	priority_queue<pi> pq;
	pq.push(make_pair(0, startAt));
	dist[startAt] = 0;

	while ( pq.size() ) {
		pi cur = pq.top();
		int curCost = -cur.fi;
		int curVertex = cur.se;
		pq.pop();
		
		if ( dist[curVertex] < curCost ) continue;

		for ( auto g: graph[curVertex] ) {
			if ( curCost + g.se > dist[g.fi] ) continue;
			dist[g.fi] = curCost + g.se;
			pq.push(make_pair(-dist[g.fi], g.fi));
		}
	}

	for ( int i = 1; i <= vertices; i++ ) {
		if ( dist[i] == INF ) {
			cout << "INF" << endl;
			continue;
		}
		cout << dist[i] << endl;
	}
    return 0;
}
