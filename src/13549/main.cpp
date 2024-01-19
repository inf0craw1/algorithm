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
int a, b;
vector<int> mapp(100001, -1);
queue<pii> q;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
bool IsSafe(int curPos) {
	if ( curPos < 0 || 100000 < curPos ) return 0;
	return 1;
}
int Warp(int curPos, int curTime) {
	if ( curPos == 0 ) return 0;
	for ( int i = curPos + curPos; i <= 100000 && i < b*2; i *= 2 ) {
		if ( mapp[i] != -1 ) continue;
		mapp[i] = curTime;
		q.push(make_pair(i, curTime));
		if ( i == b ) return 1;
	}
	return 0;
}

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);


	cin >> a >> b;
	
	if ( a == b ) {
		cout << 0 << endl;
		return 0;
	}

	mapp[a] = 0;
	q.push(make_pair(a, 0));
	Warp(a, 0);
	
	while ( q.size() ) {
		pii cur = q.front();
		q.pop();
		int curPos = cur.fi;
		int curStep = cur.se;

		if ( curPos == b ) {
			cout << curStep << endl;
			return 0;
		}

		if ( Warp(curPos, curStep) ) {
			cout << curStep << endl;
			return 0;
		}
		if ( IsSafe(curPos - 1) && mapp[curPos - 1] == -1 ) {
			q.push(make_pair(curPos - 1, curStep + 1));
			if ( Warp(curPos - 1, curStep + 1) ) {
				cout << curStep + 1 << endl;
				return 0;
			}
		}
		if ( IsSafe(curPos + 1) && mapp[curPos + 1] == -1 ) {
			q.push(make_pair(curPos + 1, curStep + 1));
			if ( Warp(curPos + 1, curStep + 1) ) {
				cout << curStep + 1 << endl;
				return 0;
			}
		}
	}

    return 0;
}
