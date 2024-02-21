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

	int size; cin >> size;
	vector<vi> graph;

	for ( int i = 0; i < size; i++ ) {
		vi tempRow;
		for ( int j = 0; j < size; j++ ) {
			int temp; cin >> temp;
			tempRow.push_back(temp);
		}
		graph.push_back(tempRow);
	}

	for ( int i = 0; i < size; i++ ) {
		queue<int> q;
		for ( int j = 0; j < size; j++ ) {
			if ( graph[i][j] ) {
				q.push(j);
			}
		}
		while ( q.size() ) {
			int cur = q.front();
			q.pop();

			for ( int j = 0; j < size; j++ ) {
				if ( graph[cur][j] && !graph[i][j] ) {
					graph[i][j] = 1;
					q.push(j);
				}
			}
		}
	}

	for ( auto row: graph ) {
		for ( auto r: row ) {
			cout << r << ' ';
		}
		cout << endl;
	}

    return 0;

}
