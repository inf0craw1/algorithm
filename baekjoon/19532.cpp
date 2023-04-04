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

	int a, b, c, d, e, f;

	cin >> a >> b >> c >> d >> e >> f;

	for ( int i = -999; i <= 999; i++ ) {
		for ( int j = -999; j <= 999; j++ ) {
			if ( a*i + b*j == c && d*i + e*j == f ) {
				cout << i << ' ' << j << endl;
				return 0;
			}
		}
	}

    return 0;
}
