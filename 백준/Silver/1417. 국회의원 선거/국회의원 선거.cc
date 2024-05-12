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
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int n; cin >> n;
	int res = 0, curCnt;

	priority_queue<pi> pq;

	for ( int i = 0; i < n; i++ ) {
		int cnt; cin >> cnt;
		if ( i == 0 ) {
			curCnt = cnt;
		}
		pq.push(make_pair(cnt, i));
	}

	while ( 1 ) {

		pi maxi = pq.top();
		pq.pop();
		if ( maxi.fi < curCnt || maxi.se == 0 ) break;
		curCnt ++;
		res ++;
		pq.push(make_pair(maxi.fi-1, maxi.se));
	}
	
	cout << res << endl;

	

    return 0;
}
