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
	vi nums(n); for ( auto &x: nums ) cin >> x;
	vi stck, res; res.resize(n, -1);

	for ( int i = 0; i < n; i++ ) {
		if ( stck.empty() || nums[stck.back()] >= nums[i] ) {
			stck.push_back(i);
			continue;
		}

		while ( !stck.empty() && nums[stck.back()] < nums[i] ) {
			res[stck.back()] = nums[i];
			stck.pop_back();
		}
		stck.push_back(i);
	}

	for ( auto r: res ) {
		cout << r << ' ';
	}
	cout << endl;

    return 0;
}
