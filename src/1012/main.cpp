#include <iostream>
#include <algorithm>
#include <vector>

#define debug if constexpr (local) std::cout
#define endl '\n'
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define pii pair<int, int>

#ifdef LOCAL
constexpr bool local = true;
#else
constexpr bool local = false;
#endif

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

/* - GLOBAL VARIABLES ---------------------------- */
int testCases, m, n, k;
vector<vector<int>> mmap;
vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
bool IsSafe(pii location) {
	return (0 <= location.fi && location.fi < n && 0 <= location.se && location.se < m);
}
pii GetSumOfPairs(pii p1, pii p2) {
	return make_pair(p1.fi + p2.fi, p1.se + p2.se);
}
pii GetFirstCabbage() {
	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < m; j++ ) {
			if ( mmap[i][j] ) return make_pair(i, j);
		}
	}
	return make_pair(-1, -1);
}
void CheckCabbages(pii location) {
	mmap[location.fi][location.se] = 0;
	for ( int i = 0; i < 4; i++ ) {
		pii newLocation = GetSumOfPairs(location, directions[i]);

		if ( IsSafe(newLocation) && mmap[newLocation.fi][newLocation.se] ) {
			CheckCabbages(newLocation);
		}
	}
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	cin >> testCases;

	for ( int t = 0; t < testCases; t++ ) {
		cin >> m >> n >> k;
		mmap.clear();
		mmap.resize(n+1, vector<int> (m+1, 0));
		int x, y;
		for ( int i = 0; i < k; i++ ) {
			cin >> x >> y;
			mmap[y][x] ++;
		}
		
		int cnt = 0;
		while ( 1 ) {
			pii firstCabbage = GetFirstCabbage();
			if ( firstCabbage.fi == -1 ) break;

			CheckCabbages(firstCabbage);
			cnt ++;
		}
		cout << cnt << endl;
	}


    return 0;
}
