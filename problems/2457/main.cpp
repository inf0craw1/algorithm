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
int GetDateScore(pi date) {
	return date.fi * 100 + date.se;
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int n; cin >> n;
	priority_queue<pair<pi, pi>> pq;

	for ( int i = 0; i < n; i++ ) {
		int startMonth, startDate, endMonth, endDate;
		cin >> startMonth >> startDate >> endMonth >> endDate;

		pq.push(make_pair(make_pair(-startMonth, -startDate), make_pair(endMonth, endDate)));
	}

	if ( GetDateScore(pq.top().fi) < -301 ) {
		cout << 0 << endl;
		return 0;
	}

	pi lastStartDate = make_pair(3, 1);
	pi lastEndDate = make_pair(3, 1);
	int res = 1;
	
	pair<pi, pi> firstTop = pq.top();
	pi firstStart = make_pair(-firstTop.fi.fi, -firstTop.fi.se);
	pi firstEnd = firstTop.se;
	cout << firstStart.fi << ' ' << firstStart.se << ", " << firstEnd.fi << ',' << firstEnd.se << endl;
	
	while ( pq.size() ) {
		pair<pi, pi> cur = pq.top();
		pi curStart = make_pair(-cur.fi.fi, -cur.fi.se);
		pi curEnd = cur.se;
		pq.pop();

		if ( GetDateScore(lastEndDate) <  GetDateScore(curStart) ) {
			if ( GetDateScore(lastEndDate) >= GetDateScore(curStart) ) {
				res ++;
				lastStartDate = curStart;
				lastEndDate = curEnd;
				cout << "Res ++ : " << curStart.fi << ' ' << curStart.se << ", " << curEnd.fi << ' ' << curEnd.se << endl;
				continue;
			}
			cout << 0 << endl;
			return 0;
		} 

		if ( GetDateScore(lastEndDate) >= GetDateScore(curEnd) ) continue;

		lastEndDate = curEnd;
		cout << "Last updated : " << curStart.fi << ' ' << curStart.se << ", " << curEnd.fi << ' ' << curEnd.se << endl;
	}

	if ( GetDateScore(lastEndDate) < 1130 ) {
		cout << 0 << endl;
		return 0;
	}

	cout << res+1 << endl;
		

    return 0;
}
