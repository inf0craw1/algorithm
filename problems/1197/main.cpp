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
	vi visit = vi(vertices+1, 0);
	vector<int, pi> edge;
	priority_queue<pair<int, pi>> q;

	for ( int i = 0; i < edges; i++ ) {
		int from, to, cost;	cin >> from >> to >> cost;
		int temp;

		edge[to] = from;
		edge[from] = to;

		if ( from == 1 ) {
			q.push(make_pair(-cost, make_pair(from, to)));
		}
	}


    return 0;
}
