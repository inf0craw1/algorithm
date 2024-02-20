#include <bits/stdc++.h>

#define debug if constexpr (local) std::cout
#define endl '\n'
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
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
int row, col, res = 0;
vector<vector<char>> mapp;
vi visited(28, 0);
vector<pi> directions = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
bool IsSafe(pi pos) {
	if ( pos.fi < 0 || pos.fi >= row || pos.se < 0 || pos.se >= col ) return 0;
	return 1;
}
void MakeRoad(pi pos, int count) {
	int CanGoMore = false;
	for ( auto d: directions ) {
		pi newPos = make_pair(pos.fi + d.fi, pos.se + d.se);
		if ( !IsSafe(newPos) ) continue;
		if ( visited[mapp[newPos.fi][newPos.se] - 'A'] ) continue;
		CanGoMore = true;
		visited[mapp[newPos.fi][newPos.se] - 'A'] = 1;
		MakeRoad(newPos, count+1);
		visited[mapp[newPos.fi][newPos.se] - 'A'] = 0;
	}
	if ( CanGoMore == false ) {
		res = max(res, count);
	}
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	cin >> row >> col;

	for ( int i = 0; i < row; i++ ) {
		vector<char> tempRow;
		for ( int j = 0; j < col; j++ ) {
			char temp; cin >> temp;
			tempRow.push_back(temp);
		}
		mapp.push_back(tempRow);
	}
	visited[mapp[0][0] - 'A'] = 1;
	MakeRoad(make_pair(0,0), 1);

	cout << res << endl;

    return 0;
}
