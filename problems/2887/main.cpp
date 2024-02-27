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
int numberOfLines;
vector<pair<pi, pi>> lines;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
void ChkIsCrossed(pair<pi, pi> line1, pair<pi, pi> line2) {
	pi line1S = line1.fi;
	pi line1E = line1.se;
	pi line2S = line2.fi;
	pi line2E = line2.se;
	double line1Gradient = (double)(line1E.se - line1S.se) / (double)(line1E.fi - line1S.fi);
	double line2Gradient = (double)(line2E.se - line2S.se) / (double)(line2E.fi - line2S.fi);
	cout << "L1 Grad : " << line1Gradient << ", L2 Grad : " << line2Gradient << endl;
	pi commonXRange = make_pair(max(line1S.fi, line2S.fi), min(line1E.fi, line2E.fi));

	cout << commonXRange.fi << ' ' << commonXRange.se << endl;

	if ( (line1S.se <= line2S.se && line1E.se >= line2E.se) || (line1S.se >= line2S.se && line1E.se <= line2E.se) ) {
		cout << "TRUE" << endl;
		return;
	}
	cout << "FALSE" << endl;

}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	cin >> numberOfLines;
	for ( int i = 0; i < numberOfLines; i++ ) {
		pi l1, l2;
		cin >> l1.fi >> l1.se >> l2.fi >> l2.se;

		if ( l1.fi <= l2.fi ) {
			lines.push_back(make_pair(l1, l2));
			continue;
		}
		lines.push_back(make_pair(l2, l1));
	}

	for ( int i = 1; i < numberOfLines; i++ ) {
		ChkIsCrossed(lines[i-1], lines[i]);
	}

	for ( auto l: lines ) {
		auto line1 = l.fi;
		auto line2 = l.se;

		cout << line1.fi << ' ' << line1.se << ',' << line2.fi << ' ' << line2.se << endl;
	}

    return 0;
}
