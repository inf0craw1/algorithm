#include <iostream>
#include <map>

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

	int m, n;
	map<ll, int> mp;

	cin >> m;
	for ( int i = 0; i < m; i++  ) {
		ll temp1;
		cin >> temp1;

		if ( mp.find(temp1) == mp.end() ) {
			mp.insert({temp1, 1});
			continue;
		}
		mp.find(temp1)->second++;
	}

	cin >> n;

	for ( int i = 0; i < n; i++ ) {
		ll temp;
		cin >> temp;
		auto res = mp.find(temp);

		if ( res != mp.end() ) {
			cout << res->second << ' ';
			continue;
		}
		cout << "0 ";
	}

	cout << endl;
    return 0;
}
