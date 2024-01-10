#include <iostream>
#include <vector>

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
int n, m;
vector<int> chk;
vector<vector<int>> graph;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
int GetRemainVertex() {
	for ( int i = 1; i <= n; i++ ) {
		if ( !chk[i] ) return i;
	}
	return -1;
}
void DFS(int vertex) {
	if ( chk[vertex] ) return;
	chk[vertex] = 1;
	
	for ( int i = 1; i <= n; i++ ) {
		if ( graph[vertex][i] ) {
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

	int vertex1, vertex2, res = 0;

	cin >> n >> m;
	chk.resize(n+1, 0);
	graph.resize(n+1, vector<int> (n+1, 0));
	for ( int i = 0; i < m; i++ ) {
		cin >> vertex1 >> vertex2;
		graph[vertex1][vertex2] ++;
		graph[vertex2][vertex1] ++;
	}

	while ( 1 ) {
		int remainVertex = GetRemainVertex();
		if ( remainVertex == -1 ) break;
		
		DFS(remainVertex);
		res ++;
	}
	
	cout << res << endl;

    return 0;
}
