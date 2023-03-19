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

	int n;
	
	cin >> n;

	for ( int i = 1; i <= n; i++ ) {
		for ( int j = n - i; j >= 1; j-- ) {
			cout << ' ';
		}
		for ( int j = 1; j <= i * 2 - 1; j++ ) {
			cout << '*';
		}
		cout << endl;
	}
	for ( int i = n - 1; i >= 1; i-- ) {
		for ( int j = n - i; j >= 1; j-- ) {
			cout << ' ';
		}
		for ( int j = 1; j <= i * 2 - 1; j++ ) {
			cout << '*';
		}
		cout << endl;	
	}

    return 0;
}
