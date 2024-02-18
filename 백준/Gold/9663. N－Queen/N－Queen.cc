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
int n, res = 0;
vector<vi> mapp;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
bool IsSafe(pi pos) {
	if ( pos.fi < 0 || pos.fi >= n || pos.se < 0 || pos.se >= n ) return 0;
	return 1;
}
void PlaceQueen(int row) {
	int curRow = row + 1;
	if ( curRow == n ) {
		res ++;
		return;
	}
	for ( int i = 0; i < n; i++ ) {
		if ( mapp[curRow][i] != 0) continue;
		for ( int j = curRow+1, k = 1; j < n; j++, k++ ) {
			mapp[j][i] --;
			if ( IsSafe(make_pair(j, i-k)) ) mapp[j][i-k]--;
			if ( IsSafe(make_pair(j, i+k)) ) mapp[j][i+k]--;
		}
		PlaceQueen(curRow);
		for ( int j = curRow+1, k = 1; j < n; j++, k++ ) {
			mapp[j][i] ++;
			if ( IsSafe(make_pair(j, i-k)) ) mapp[j][i-k]++;
			if ( IsSafe(make_pair(j, i+k)) ) mapp[j][i+k]++;
		}
	}
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	cin >> n;
	mapp.resize(n, vi (n, 0));
	PlaceQueen(-1);

	cout << res << endl;
    return 0;
}
