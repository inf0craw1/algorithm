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
int numberOfLines, numberOfGroups = 0;
vector<pair<pi, pi>> lines;
vector<vi> connectionMap;
vi isGroupedLine; 
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
pi GetCommonXRange(pi line1LeftPoint, pi line1RightPoint, pi line2LeftPoint, pi line2RightPoint) {
	int startX = max(line1LeftPoint.fi, line2LeftPoint.fi);
	int endX = min(line1RightPoint.fi, line2RightPoint.fi);

	return make_pair(startX, endX);
}
bool ChkIsCrossed(pair<pi, pi> line1, pair<pi, pi> line2) {
	pair<double, double> line1LeftPoint = line1.fi;
	pair<double, double> line1RightPoint = line1.se;
	pair<double, double> line2LeftPoint = line2.fi;
	pair<double, double> line2RightPoint = line2.se;
	double line1Gradient = (double)(line1LeftPoint.se - line1RightPoint.se) / (double)(line1LeftPoint.fi - line1RightPoint.fi);
	double line2Gradient = (double)(line2LeftPoint.se - line2RightPoint.se) / (double)(line2LeftPoint.fi - line2RightPoint.fi);

	pi xRange = GetCommonXRange(line1LeftPoint, line1RightPoint, line2LeftPoint, line2RightPoint);

	if ( xRange.fi > xRange.se ) return false;

	if ( line1LeftPoint.fi != line1RightPoint.fi ) {
		line1LeftPoint.se = line1LeftPoint.se + (xRange.fi - line1LeftPoint.fi) * line1Gradient;
		line1LeftPoint.fi = xRange.fi;
		line1RightPoint.se = line1RightPoint.se + (xRange.se - line1RightPoint.fi) * line1Gradient;
		line1RightPoint.fi = xRange.se;
	}
	if ( line2LeftPoint.fi != line2RightPoint.fi ) {
		line2LeftPoint.se = line2LeftPoint.se + (xRange.fi - line2LeftPoint.fi) * line2Gradient;
		line2LeftPoint.fi = xRange.fi;
		line2RightPoint.se = line2RightPoint.se + (xRange.se - line2RightPoint.fi) * line2Gradient;
		line2RightPoint.fi = xRange.se;
	}

	if ( line1LeftPoint == line2LeftPoint || line1LeftPoint == line2RightPoint || line1RightPoint == line2LeftPoint || line1RightPoint == line2RightPoint  ) {
		return true;
	}

	if ( (line1LeftPoint.se - line2LeftPoint.se) * (line1RightPoint.se - line2RightPoint.se) <= 0 ) return true;
	return false;
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	for ( int i = 0; i < 2; i++ ) {
		pi linePoint1, linePoint2;
		cin >> linePoint1.fi >> linePoint1.se >> linePoint2.fi >> linePoint2.se;
		if ( linePoint1.fi > linePoint2.fi ) {
			lines.push_back(make_pair(linePoint2, linePoint1));
		} else {
			lines.push_back(make_pair(linePoint1, linePoint2));
		}
	}

	cout << (ChkIsCrossed(lines[0], lines[1]) ? 1 : 0) << endl;
    return 0;
}
