#include <iostream>
#include <vector>
#include <cmath>

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
vector<pair<pii, pii>> divider = { {{0,0}, {1,1}},
									{{0,1}, {1,2}},
									{{0,2}, {1,3}},
									{{1,0}, {2,1}},
									{{1,2}, {2,3}},
									{{2,0}, {3,1}},
									{{2,1}, {3,2}},
									{{2,2}, {3,3}}};
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
void OverwriteStars(pii startPos, pii endPos) {
	if ( startPos.fi == endPos.fi && startPos.se == endPos.se ) {
		mapp[startPos.fi][startPos.se] = '*';
		return;
	}

	int divisionSize = (endPos.fi - startPos.fi + 1) / 3;

	for ( auto d: divider ) {
		pii dSPos = d.fi;
		pii dEPos = d.se;
		pii newSPos = make_pair(startPos.fi + dSPos.fi * divisionSize, startPos.se + dSPos.se * divisionSize);
		pii newEPos = make_pair(startPos.fi + dEPos.fi * divisionSize - 1, startPos.se + dEPos.se * divisionSize - 1);
		OverwriteStars(newSPos, newEPos);
	}
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	cin >> n;

	mapp.resize(n, vector<char> (n, ' '));

	OverwriteStars(make_pair(0, 0), make_pair(n-1, n-1));

	for ( auto row: mapp ) {
		for ( auto r: row ) {
			cout << r;
		}
		cout << endl;
	}

    return 0;
}
