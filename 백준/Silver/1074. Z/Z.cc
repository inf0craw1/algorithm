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
int n, totalSize, row, col, cnt = 0;
vector<pair<pii, pii>> divider = {{{0, 0}, {-1, -1}},
							{{0, 1}, {-1, 0}},
							{{1, 0}, {0, -1}},
							{{1, 1}, {0, 0}}};
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
void VisitZShape(pii sPos, pii ePos) {
	int halfSize = (ePos.fi - sPos.fi + 1) / 2;

	if ( sPos.fi == row && sPos.se == col ) {
		cout << cnt << endl;
		return;
	}

	for ( auto d: divider ) {
		pii dSPos = d.fi;
		pii dEPos = d.se;
		pii newSPos = make_pair(sPos.fi + dSPos.fi * halfSize, sPos.se + dSPos.se * halfSize);
		pii newEPos = make_pair(ePos.fi + dEPos.fi * halfSize, ePos.se + dEPos.se * halfSize);
		if ( newSPos.fi <= row && row <= newEPos.fi && newSPos.se <= col && col <= newEPos.se ) {
			VisitZShape(newSPos, newEPos);
			continue;
		}
		cnt += pow(halfSize, 2);
	}
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	cin >> n >> row >> col;

	totalSize = pow(2, n);

	VisitZShape(make_pair(0, 0), make_pair(totalSize - 1, totalSize - 1));

    return 0;
}
