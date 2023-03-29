#include <iostream>

#define debug if constexpr (local) std::cout
#define endl '\n'
#define fi first
#define se second
#define all(x) x.begin(),x.end()

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

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int n;
	ll x, y;
	pair<ll, ll> mini = {10e8, 10e8}, maxi = { -10e8, -10e8 };

	cin >> n;

	for ( int i = 0; i < n; i++ ) {
		cin >> x >> y;

		mini.first = min(mini.first, x);
		mini.second = min(mini.second, y);
		maxi.first = max(maxi.first, x);
		maxi.second = max(maxi.second, y);
	}

	cout << (maxi.first - mini.first) * ( maxi.second - mini.second ) << endl;

    return 0;
}
