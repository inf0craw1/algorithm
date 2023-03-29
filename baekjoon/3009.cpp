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

	int arr[3][2], res1, res2;

	for ( int i = 0; i < 3; i++ ) {
		for ( int j = 0; j< 2; j++ ) {
			cin >> arr[i][j];
		}
	}

	if ( arr[0][0] == arr[1][0] ) {
		res1 = arr[2][0];
	}
	else if ( arr[0][0] == arr[2][0] ) {
		res1 = arr[1][0];
	}
	else {
		res1 = arr[0][0];
	}

	if ( arr[0][1] == arr[1][1] ) {
		res2 = arr[2][1];
	}
	else if ( arr[0][1] == arr[2][1] ) {
		res2 = arr[1][1];
	}
	else {
		res2 = arr[0][1];
	}

	cout << res1 << ' ' << res2 << endl;

    return 0;
}
