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

	int num, target;

	cin >> num >> target;

	int  i = 0;

	for ( i = 0; num < target; i++ ) {
		if ( target % 10 == 1 ) {
			target /= 10;
			continue;
		}
		if ( target % 2 == 0 ) {
			target /= 2;
			continue;
		}
		cout << -1 << endl;
		return 0;
	}
	if ( num == target ) {
		cout << i+1 << endl;
		return 0;
	}

	cout << -1 << endl;

    return 0;
}
