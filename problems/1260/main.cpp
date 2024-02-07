#include <iostream>
#include <vector>
#include <queue>

#define debug if constexpr (local) std::cout
#define endl '\n'
#define fi first
#define se second
#define all(x) x.begin(),x.end()

#ifdef LOCAL
constexpr bool local = true;
#else
constexpr bool local = false;
#endif

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

/* - GLOBAL VARIABLES ---------------------------- */
int n, m, start, vertex1, vertex2;
vector<int> BFSChk, DFSChk;
vector<vector<int>> graph;
queue<int> q;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
void DFS(int currentVertex) {
	if ( DFSChk[currentVertex] ) return;
	DFSChk[currentVertex] ++;
	cout << currentVertex << ' ';
	for ( int i = 1; i <= n; i++ ) {
		if ( graph[currentVertex][i] ) {
			DFS(i);
		}
	}
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	cin >> n >> m >> start;
	graph.resize(n+1, vector<int> (n+1, 0));
	BFSChk.resize(n+1, 0);
	DFSChk.resize(n+1, 0);

	for ( int i = 0; i < m; i++ ) {
		cin >> vertex1 >> vertex2;
		graph[vertex1][vertex2]++;
		graph[vertex2][vertex1]++;
	}

	DFS(start);
	cout << endl;

	q.push(start);
	BFSChk[start] ++;
	while ( !q.empty() ) {
		int currentVertex = q.front();
		cout << currentVertex << ' ';
		q.pop();
		for ( int i = 1; i <= n; i++ ) {
			if ( graph[currentVertex][i] && !BFSChk[i] ) {
				q.push(i);
				BFSChk[i] ++;
			}
		}
	}
	cout << endl;

    return 0;
}
