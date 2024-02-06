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
int n;
vector<vector<char>> mapp;
vector<pii> triangle = {{0,2}, {1,1}, {1,3}, {2,0}, {2,1}, {2,2}, {2,3}, {2,4}};
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
void OverwriteTriangle(pii sPos) {
	for ( auto t: triangle ) {
		mapp[sPos.fi + t.fi][sPos.se + t.se] = '*';
	}
}
void OverwriteStars(pii sPos, pii ePos) {
	if ( ePos.fi - sPos.fi + 1 == 3 ) {
		OverwriteTriangle(sPos);
		return;
	}

	int height = ePos.fi - sPos.fi + 1;
	int width = ePos.se - sPos.se + 1;
	OverwriteStars(make_pair(sPos.fi, sPos.se + width / 4 ), make_pair(sPos.fi + height / 2 - 1, sPos.se + width / 4 * 3 + 1 ));
	OverwriteStars(make_pair(sPos.fi + height / 2, sPos.se), make_pair(ePos.fi, sPos.se + width / 2 - 1));
	OverwriteStars(make_pair(sPos.fi + height / 2, ((sPos.se + width / 2 ) % 2) == 0 ? sPos.se + width / 2 : sPos.se + width / 2 - 1), make_pair(ePos.fi, ePos.se));
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	cin >> n;

	mapp.resize(n, vector<char> (n*2-1, ' '));

	OverwriteStars(make_pair(0, 0), make_pair(n - 1, n * 2 - 1));

	for ( auto row: mapp ) {
		for ( auto r: row ) {
			cout << r;
		}
		cout << endl;
	}

    return 0;
}
