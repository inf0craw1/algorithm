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
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
bool IsSafe(int curPos) {
	if ( curPos < 0 || curPos > 500000 ) return false;
	return true;
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int start, target; cin >> start >> target;
	priority_queue<pi> finderQ;

	unordered_set<int> finderTrace;
	unordered_map<int, int> targetTrace; 

	int curTarget = target;
	int step = 1, curTime = 0;

	while ( curTarget <= 500000 ) {
		targetTrace.insert({curTarget, curTime++});
		curTarget += step++;
	}

	finderQ.push(make_pair(0, start));

	while ( 1 ) {
		pi cur = finderQ.top();
		int curTime = -cur.fi;
		int curPos = cur.se;

		if ( finderTrace.find(curPos) != finderTrace.end() ) continue;

		auto foundTargetTrace = targetTrace.find(curPos);

		if ( foundTargetTrace != targetTrace.end() && foundTargetTrace->se == curTime ) {
			cout << curTme << endl;
			return 0;
		}

		if ( finderTrace.find(curPos-1) == finderTrace.end() ) finderQ.push({curTime+1, curPos-1});
		if ( finderTrace.find(curPos+1) == finderTrace.end() ) finderQ.push({curTime+1, curPos+1});
		if ( finderTrace.find(curPos*2) == finderTrace.end() ) 
		f inderQ.push({curTime+1, curPos-1});

	}

    return 0;
}
