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
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int n; cin >> n;
	vi nums(n);
	for ( auto &x: nums ) cin >> x;
	sort(all(nums));

	int res = 0;

	for ( int i = 0; i < n; i++ ) {
		int s = 0, e = n - 1;
		if ( i == 0 ) s++;
		if ( i == n-1 ) e--;

		while ( s < e ) {
			if ( nums[s] + nums[e] == nums[i] ) {
				res ++;
				break;
			}
			if ( nums[s] + nums[e] < nums[i] ) {
				s++;
				if ( s == i ) s++;
				continue;
			}
			e--;
			if ( e == i ) e--;
		}
	}

	cout << res << endl;

	return 0;
}
