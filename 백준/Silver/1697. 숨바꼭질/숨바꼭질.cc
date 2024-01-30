#include <iostream>
#include <algorithm>
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
bool IsSafe(int pos) {
	if ( pos < 0 || pos > 100000 ) return 0;
	return 1;
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int a, b;
	queue<pii> q;
	vector<int> mapp(100001, -1);

	cin >> a >> b;

	q.push(make_pair(a, 0));

	while ( q.size() ) {
		pii cur = q.front();
		q.pop();
		int curPos = cur.fi;
		int curStep = cur.se;

		if ( curPos == b ) {
			cout << curStep << endl;
			return 0;
		}

		if ( IsSafe(curPos - 1) && mapp[curPos - 1] == -1 ) {
			q.push(make_pair(curPos - 1, curStep + 1));
			mapp[curPos - 1] = 0;
		}
		if ( IsSafe(curPos + 1) && mapp[curPos + 1] == -1 ) {
			q.push(make_pair(curPos + 1, curStep + 1));
			mapp[curPos + 1] = 0;
		} 
		if ( IsSafe(curPos * 2) && mapp[curPos * 2] == -1 ) {
			q.push(make_pair(curPos * 2, curStep + 1));
			mapp[curPos * 2] = 0;
		} 
	}


    return 0;
}
