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
int CheckLineGroupSize(int lineIdx) {
	int cnt = 1;
	isGroupedLine[lineIdx] = 1;
	queue<int> q;
	q.push(lineIdx);

	while ( q.size() ) {
		int curLineIdx = q.front();
		q.pop();
		for ( int i = 0; i < numberOfLines; i++ ) {
			if ( connectionMap[curLineIdx][i] && isGroupedLine[i] == 0 ) {
				q.push(i);
				isGroupedLine[i] = 1;
				cnt ++;
			}
		}
	}

	return cnt;
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	cin >> numberOfLines;
	connectionMap.resize(numberOfLines, vi (numberOfLines, 0));
	isGroupedLine.resize(numberOfLines, 0);

	for ( int i = 0; i < numberOfLines; i++ ) {
		pi line1, line2;
		cin >> line1.fi >> line1.se >> line2.fi >> line2.se;
		if ( line1.fi > line2.fi ) {
			lines.push_back(make_pair(line2, line1));
		} else {
			lines.push_back(make_pair(line1, line2));
		}
		for ( int j = 0; j < i; j++ ) {
			if ( ChkIsCrossed(lines[i], lines[j]) ) {
				connectionMap[i][j] = 1;
				connectionMap[j][i] = 1;
				continue;
			}
		}
	}

	int maxi = 0;

	for ( int i = 0; i < numberOfLines; i++ ) {
		if ( isGroupedLine[i] ) continue;
		maxi = max( maxi, CheckLineGroupSize(i));
		numberOfGroups ++;
	}
	
	cout << numberOfGroups << endl << maxi << endl;
    return 0;
}
