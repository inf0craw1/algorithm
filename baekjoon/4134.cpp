#include <iostream>
#include <vector>

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

	int n;
	unsigned int num;

	cin >> n;

	for ( int i = 0; i < n; i++ ) {
		cin >> num;

		if ( num < 2 ) {
			cout << 2 << endl;
			continue;
		}

		for ( unsigned int j = num; ; j ++ ) {
			bool chk = false;

			for ( unsigned int k = 2; k * k < j; k++ ) {
				if ( j % k == 0 ) {
					chk = true;
					break;
				}
			}
			
			if ( !chk ) {
				cout << j << endl;
				break;
			}
		}

	}

    return 0;
}
