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

	vi nums(8);
	for ( auto &x: nums ) cin >> x;
	int type = nums[1] - nums[0];

	for ( int i = 2; i < 8; i++ ) {
		if ( nums[i] - nums[i-1] != type ) {
			cout << "mixed" << endl;
			return 0;
		}
	}

	if ( type == -1 ) {
		cout << "descending" << endl;
		return 0;
	}

	cout << "ascending" << endl;

    return 0;
}
