#include <iostream>
#include <algorithm>
#include <set>

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

	int n, temp, cnt = 0;
	ll res = 0;
	multiset<ll> nums;


	cin >> n;

	for ( int i = 0; i < n; i++ ) {
		cin >> temp;
		nums.insert(temp);
	}

	for ( int i = 0; i < n - 1; i++ ) {
		auto it = nums.begin();
		ll first = *(it++);
		ll second = *it;
		ll sum = first + second;
		res += sum;
		nums.erase(first);
		nums.erase(second);
		nums.insert(sum);
	}

	cout << res << endl;
    return 0;
}
