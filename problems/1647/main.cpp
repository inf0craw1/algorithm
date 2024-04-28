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
int vertices, edges;
vi visited, parent;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
int FindParent(int curNode) {
	if ( curNode == parent[curNode] ) return curNode;
	parent[curNode] = parent[parent[curNode]];
	return FindParent(parent[curNode]);
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	cin >> vertices >> edges;
	visited = vi(vertices+1, 0);
	parent = {0};
	priority_queue<pair<int, pi>> q;
	int res = 0;
	int maxCost = 0;

	for ( int i = 0; i < vertices; i++  ) {
		parent.push_back(i+1);
	}

	for ( int i = 0; i < edges; i++ ) {
		int from, to, cost;	cin >> from >> to >> cost;

		q.push(make_pair(-cost, make_pair(from, to)));
	}

	while ( q.size() ) {
		pair<int, pi> cur = q.top();
		int curCost = -cur.fi;
		pi curNode = cur.se;

		q.pop();

		int root1 = FindParent(curNode.fi);
		int root2 = FindParent(curNode.se);

		if ( root1 == root2 ) continue;

		res += curCost;
		maxCost = max(maxCost, curCost);
		parent[root1] = min(root1, root2);
		parent[root2] = min(root1, root2);

	}

	cout << res - maxCost << endl;


    return 0;
}
