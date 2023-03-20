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

	int arr[10][10] = {};
	int max = -1, x, y;

	for ( int i = 1; i < 10; i++ ) {
		for ( int j = 1; j < 10; j++ ) {
			cin >> arr[i][j];
			if ( max < arr[i][j] ) {
				x = j;
				y = i;
				max = arr[i][j];
			}
		}
	}

	cout << max << endl << y << ' ' << x << endl;

    return 0;
}
