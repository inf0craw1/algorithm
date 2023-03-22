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

	int num, x, y, max_x = 0, max_y = 0;
	int arr[101][101] = {};
	int res = 0;
	
	cin >> num;

	for ( int i = 0; i < num; i++ ) {
		cin >> x >> y;
		
		if ( max_x < x ) max_x = x;
		if ( max_y < y ) max_y = y;

		for ( int i = x; i < x + 10; i++ ) {
			for ( int j = y; j < y + 10; j++ ) {
				arr[i][j] = 1;
			}
		}
	}

	for ( int i = 1; i <= max_x + 10; i++ ) {
		for ( int j = 1; j <= max_y + 10; j++ ) {
			res += arr[i][j];
		}
	}

	cout << res << endl;

    return 0;
}
