#include <iostream>
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
int n, maxi = 0, cnt;
vector<vector<int>> mapp, m;
vector<pii> directions = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
pii GetSafePosition(int level) {
	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < n; j++ ) {
			if ( m[i][j] >= level ) {
				return make_pair(i, j);
			}
		}
	}
	return make_pair(-1, -1);
}

bool IsSafe(pii pos) {
	return ( 0 <= pos.fi && pos.fi < n && 0 <= pos.se && pos.se < n );
}

pii GetSumOfPair(pii p1, pii p2) {
	return make_pair(p1.fi + p2.fi, p1.se + p2.se);
}

void DFS(pii pos, int level) {
	if ( m[pos.fi][pos.se] < level ) return;
	m[pos.fi][pos.se] = -1;
	for ( int i = 0; i < 4; i++ ) {
		pii newPos = GetSumOfPair(pos, directions[i]);
		if ( IsSafe(newPos) && m[newPos.fi][newPos.se] >= level ) {
			DFS(newPos, level);
		}
	}
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int temp;

	cin >> n;

	for ( int i = 0; i < n; i++ ) {
		vector<int> tempRow;
		for ( int j = 0; j < n; j++ ) {
			cin >> temp;
			tempRow.push_back(temp);
		}
		mapp.push_back(tempRow);
	}

	for ( int l = 1; l <= 100; l++ ) {
		m = mapp;
		cnt = 0;
		while ( 1 ) {
			pii safePosition = GetSafePosition(l);
			if ( safePosition.fi == -1 ) break;

			DFS(safePosition, l);
			cnt ++;
		}
		maxi = max(maxi, cnt);
	}

	cout << maxi << endl;

    return 0;
}
