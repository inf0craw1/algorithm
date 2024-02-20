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

	ll res = 0;
	ll n, targetDivider; cin >> n >> targetDivider;
	vi accRemains;
	vi accRemainsCount(targetDivider, 0);

	accRemains.push_back(0);

	for ( int i = 1; i <= n; i++ ) {
		ll temp; cin >> temp;
		ll curAccRemain = (accRemains.back() + temp) % targetDivider;
		accRemains.push_back(curAccRemain);
		accRemainsCount[curAccRemain]++;
		if ( curAccRemain == 0 ) res++;
	}

	for ( auto a: accRemainsCount ) {
		res += a * (a-1) / 2;
	}

	cout << res << endl;

    return 0;
}
