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

	ll n, res = 0, temp; cin >> n;
	unordered_multiset<ll> nums;

	for ( int i = 0; i < n; i++ ) {
		cin >> temp;
		nums.insert(temp);
	}

	for ( auto num: nums ) {
		unordered_multiset<ll> remainNums = nums;
		auto it = remainNums.find(num);

		remainNums.erase(it);

		for ( auto r: remainNums ) {
			unordered_multiset<ll> remainRemainNums = remainNums;
			auto removeTarget = remainRemainNums.find(r);
			remainRemainNums.erase(removeTarget);
			
			auto it = remainRemainNums.find(num-r);
			if ( it != remainRemainNums.end() ) {
				res ++;
				break;
			}
		}
	}

	cout << res << endl;

	return 0;
}
