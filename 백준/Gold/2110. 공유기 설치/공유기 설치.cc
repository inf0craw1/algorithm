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
int house, router, s = 1, e, maxi = 0;
vi houses;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
bool CheckPlaceRouters(int gap) {
	int remainRouters = router - 1;
	int distance = 0;
	vi houseWithRouter;
	houseWithRouter.push_back(houses[0]);

	for ( int i = 1; i < house; i++ ) {
		distance += houses[i] - houses[i-1];
		if ( distance >= gap ) {
			houseWithRouter.push_back(houses[i]);
			remainRouters--;
			distance = 0;
		}
	}
	if ( remainRouters <= 0 ) return 1;
	return 0;
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int temp;
	cin >> house >> router;
	for ( int i = 0; i < house; i++ ) {
		cin >> temp;
		houses.push_back(temp);
	}

	sort(all(houses));

	e = houses[house-1] - houses[0];
	while (s <= e) {
		int mid = (e+s) / 2;
		int res = CheckPlaceRouters(mid);

		if ( res ) {
			s = mid + 1;
			maxi = max(maxi, mid);
			continue;
		}
		e = mid - 1;
	}

	cout << maxi << endl;

    return 0;
}
