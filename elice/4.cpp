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
typedef struct Node {
	int idx;
	int moverMax;
	vector<struct Node*> children;
} Node;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
Node* GetNewNode(int idx) {
	Node *newNode = new Node();

	newNode->idx = idx;

	return newNode;
}
int GetScore(Node* cur) {
	if ( cur->children.size() == 0 ) return cur->idx;

	int curMaxi = -INF;

	for ( auto child: cur->children ) {
		int curScore = GetScore(child);
		curMaxi = max(curMaxi, cur->idx - curScore);
	}

	cur->moverMax = curMaxi;
	return cur->moverMax;
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int vertices; cin >> vertices;
	vector<unordered_set<int>> connectedLists(vertices+1, unordered_set<int>{});
	vector<Node*> allNodes(vertices+1, NULL);

	for ( int i = 0; i < vertices; i++ ) {
		int n1, n2; cin >> n1 >> n2;
		connectedLists[n1].insert(n2);
		connectedLists[n2].insert(n1);
	}

	queue<int> q;
	q.push(1);
	while( q.size() ) {
		int cur = q.front();
		q.pop();

		for ( auto child: connectedLists[cur] ) {
			connectedLists[child].erase(cur);
			q.push(child);
		}
	}

	for ( int i = 1; i <= vertices; i++ ) {
		allNodes[i] = GetNewNode(i);
	}

	for ( int i = 1; i <= vertices; i++ ) {
		if ( connectedLists[i].size() == 0 ) allNodes[i]->moverMax = allNodes[i]->idx;
		for ( auto c: connectedLists[i] ) {
			allNodes[i]->children.push_back(allNodes[c]);
		}
	}

 	GetScore(allNodes[1]);

	for ( int i = 1; i <= vertices; i++ ) {
		cout << (allNodes[i]->moverMax >= 0 ? 1 : 0) << endl;
	}
    return 0;
}
