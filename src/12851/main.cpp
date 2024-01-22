#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

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
 
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
bool IsSafe(int pos)  {
	if ( pos < 0 || pos > 100000 ) return 0;
	return 1;
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int a, b, cnt = 0, minTime = -1;
	vector<int> mapp(100001, 0);
	queue<pii> q;

	cin >> a >> b;

	mapp[a] = 1;
	q.push(make_pair(a, 0));
	
	while ( q.size() ) {
		pii cur = q.front();
		q.pop();
		int curPos = cur.fi;
		int curTime = cur.se;
		vector<int> nextPositions;

		cout << curPos << ' ' << curTime << endl;

		if ( minTime != -1 && minTime < curTime ) {
			cout << minTime << endl << cnt << endl;
			return 0;
		}
		if ( curPos == b ) {
			minTime = curTime;
			cnt ++;
			continue;
		}
		if ( IsSafe(curPos - 1) && ( !mapp[curPos - 1] || mapp[curPos - 1] == curTime + 1 )) {
			q.push(make_pair(curPos - 1, curTime + 1));
			nextPositions.push_back(curPos - 1);
		}
		if ( IsSafe(curPos + 1) && ( !mapp[curPos + 1] || mapp[curPos + 1] == curTime + 1 )) {
			q.push(make_pair(curPos + 1, curTime + 1));
			nextPositions.push_back(curPos + 1);
		}
		if ( IsSafe(curPos * 2) && ( !mapp[curPos * 2] || mapp[curPos * 2] == curTime + 1 )) {
			q.push(make_pair(curPos * 2, curTime + 1));
			nextPositions.push_back(curPos * 2);
		}
		for ( auto n: nextPositions ) {
			mapp[n] = curTime + 1;
		}
	}

    return 0;
}
