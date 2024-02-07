#include <iostream>
#include <algorithm>
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
int n, temp;
pii res;
vector<vector<int>> mapp;
vector<pair<pii, pii>> divider = {{{0, 0}, {-1, -1}},
							{{0, 1}, {-1, 0}},
							{{1, 0}, {0, -1}},
							{{1, 1}, {0, 0}}};
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
pii CheckIsOneColor(pii sPos, pii ePos) {
	int cnt = 0, totalSize = pow(ePos.fi - sPos.fi + 1, 2);

	for ( int i = sPos.fi; i <= ePos.fi; i++ ) {
		for ( int j = sPos.se; j <= ePos.se; j++ ) {
			cnt += mapp[i][j];
		}
	}
	if ( cnt == totalSize ) return make_pair(0, 1);
	if ( cnt == 0 ) return make_pair(1, 0);
	return make_pair(-1, -1);
}
pii CutPaper(pii sPos, pii ePos) {
	int halfSize = (ePos.fi - sPos.fi + 1) / 2;
	pii oneColor, res = make_pair(0, 0);


	oneColor = CheckIsOneColor(sPos, ePos);
	if ( oneColor.fi != -1 ) {
		return oneColor;
	}
	
	for ( auto d: divider ) {
		pii dSPos = d.fi;
		pii dEPos = d.se;
		pii newSPos = make_pair(sPos.fi + dSPos.fi * halfSize, sPos.se + dSPos.se * halfSize);
		pii newEPos = make_pair(ePos.fi + dEPos.fi * halfSize, ePos.se + dEPos.se * halfSize);
		pii tempRes = CutPaper(newSPos, newEPos);
		res.fi += tempRes.fi;
		res.se += tempRes.se;
	}

	return res;
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	cin >> n;

	for ( int i = 0; i < n; i++ ) {
		vector<int> tempRow;
		for ( int j = 0; j < n; j++ ) {
			cin >> temp;
			
			tempRow.push_back(temp);
		}
		mapp.push_back(tempRow);
	}

	res = CutPaper(make_pair(0, 0), make_pair(n-1, n-1));

	cout << res.fi << endl << res.se << endl;
    return 0;
}
