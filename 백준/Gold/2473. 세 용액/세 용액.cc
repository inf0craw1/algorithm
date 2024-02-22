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
	vi nums(n); for ( auto &x: nums ) cin >> x;
	ll mini = LINF;
	vi miniNums;

	sort(all(nums));

	for ( int i = 0; i < n-2; i++ ) {
		for (int j = i+1; j < n-1; j++) {
			ll curMini = LINF, curMiniM;
			int curS = j+1, curE = n-1;

			while ( curS <= curE ) {
				int curMid = (curS + curE) / 2;
				ll curAcidity = nums[i] + nums[curMid] + nums[j];

				if ( abs(curMini) > abs(curAcidity) ) {
					curMini = curAcidity;
					curMiniM = curMid;
				}

				if ( curAcidity < 0) {
					curS = curMid + 1;
					continue;
				}

				curE = curMid - 1;
			}

			if ( abs(mini) > abs(curMini) ) {
				mini = curMini;
				miniNums = {i, j, curMiniM};
			}
		}
	}

	sort(all(miniNums));

	for ( auto m: miniNums ) {
		cout << nums[m] << ' ';
	}
	cout << endl;

    return 0;
}
