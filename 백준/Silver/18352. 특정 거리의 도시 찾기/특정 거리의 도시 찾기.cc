#include <bits/stdc++.h>

#define debug if constexpr (local) std::cout
#define endl '\n'
#define INF 0x7fffffff
#define LINF 0x7fffffffffffffff
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

#ifdef LOCAL
constexpr bool local = true;
#else
constexpr bool local = false;
#endif

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
typedef unsigned long long ull;

/* - GLOBAL VARIABLES ---------------------------- */
int cities, roads, targetDist, startAt;
vector<vi> graph;
vi dist;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
void dijikstra() {
	dist[startAt] = 0;

	priority_queue<pi> pq;
	pq.push(make_pair(0, startAt));

	while ( pq.size() ) {
		pi cur = pq.top();
		int curCost = -cur.fi;
		int curCity = cur.se;
		pq.pop();
		if ( curCost > dist[curCity] ) continue;

		for ( auto g: graph[curCity] ) {
			if ( dist[g] < curCost+1 ) continue;
			dist[g] = curCost + 1;
			pq.push(make_pair(-(curCost+1), g));
		}
	}
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	cin >> cities >> roads >> targetDist >> startAt;
	graph.resize(cities+1, vi(0, 0));
	dist.resize(cities+1, INF);

	for ( int i = 0; i < roads; i++ ) {
		int from, to; cin >> from >> to;

		graph[from].push_back(to);
	}

	dijikstra();

	bool isExist = false;
	for ( int i = 1; i <= cities; i++ ) {
		if ( dist[i] == targetDist ) {
			cout << i << endl;
			isExist = true;
		}
	}

	if ( !isExist ) cout << -1 << endl;

    return 0;
}
