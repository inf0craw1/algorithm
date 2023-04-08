#include <iostream>
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

	int m, n;
	set<ll> s1;

	cin >> m;
	for ( int i = 0; i < m; i++ ) {
		ll temp;
		cin >> temp;
		s1.insert(temp);
	}


	cin >> n;
	for ( int i = 0; i < n; i++ ) {
		ll temp;
		cin >> temp;
		if ( s1.find(temp) != s1.end() ) {
			cout << 1 << ' ';
		} else {
			cout << 0 << ' ';
		}
	}

	cout << endl;

    return 0;
}
