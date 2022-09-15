#include <bits/stdc++.h>

#define debug if constexpr (local) std::cout
#define endl '\n'
#define fi first
#define se second
#define all(x) x.begin(),x.end()

#ifdef local
constexpr bool local = true;
#else
constexpr bool local = false;
#endif

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

/* - global variables ---------------------------- */
 
/* ----------------------------------------------- */

/* - functions ----------------------------------- */

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int n, counter = 1;

	cin >> n;

	for (counter = 1; ; n -= counter++) {
		if ( n - counter <= 0 ) {
			if ( counter % 2 == 0 ) {
				cout << n << '/' << counter - n + 1 << endl;
				return 0;
			}
			cout << counter - n + 1 << '/' << n << endl;
			return 0;
		}
	}

    return 0;
}
