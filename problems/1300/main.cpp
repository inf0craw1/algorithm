#include <bits/stdc++.h>

#define debug if constexpr (local) std::cout
#define endl '\n'
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

#ifdef LOCAL
constexpr bool local = true;
#else
constexpr bool local = false;
#endif

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
typedef unsigned long long ull;

/* - GLOBAL VARIABLES ---------------------------- */
int n, k, maxi = 0;
int s = 1, e, mid;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
int GetNthNum(int target) {
	int res = 0;
	for ( int i = 1; i <= n; i++ ) {
		res += min(n, target/i);
	}

	return res+1;
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	cin >> n >> k;

	e = k;

	while ( s <= e ) {
		mid = (s+e) / 2;
		int nth = GetNthNum(mid - 1);
		if ( nth <= k ) {
			maxi = max(maxi, mid);
			s = mid + 1;
			continue;
		}
		e = mid - 1;
	}

	cout << maxi << endl;
    return 0;
}
