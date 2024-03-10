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
	vector<vi> mapp(vertices+1, vi(0, 0));

	for ( int i = 0; i < edges; i++ ) {
		pi edge; cin >> edge.fi >> edge.se;

		mapp[edge.fi].push_back(edge.se);
		mapp[edge.se].push_back(edge.fi);
	}

	vi dist(vertices+1, INF);
	dist[1] = 0;
	priority_queue<pi> q;
	q.push(make_pair(0, 1));
	ll res = 0, cnt = 0;

	while ( q.size() ) {
		pi cur = q.top();
		q.pop();

		int curDist = -cur.fi;
		int curPos = cur.se;
		
		if ( curDist > dist[curPos] ) continue;

		for ( auto to: mapp[curPos] ) {
			if ( dist[to] > curDist + 1 ) {
				q.push(make_pair(-(curDist+1), to));
				dist[to] = curDist + 1;
				res = max(res, dist[to]);
			}
		}
	}

	ll mini = INF;

	for ( ll i = 1; i <= vertices; i++ ) {
		if ( dist[i] == res ) {
			mini = min(mini, i);
			cnt++;
		}
	}

	cout << mini << ' ' << res << ' ' << cnt << endl;
    return 0;
}
