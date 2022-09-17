#include <bits/stdc++.h>

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

	int num;

	cin >> num;

	for ( int i = num / 5; i >= 0; i-- ) {
		for ( int j = 0; i * 5 + j * 3 <= num; j++ ) {
			if ( i * 5 + j * 3 == num ) { 
				cout << i + j << endl;
				return 0;
			}
		}
	}

	cout << -1 << endl;

    return 0;
}
