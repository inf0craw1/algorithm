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

int getSumOfEachDigit(int n) {
	int res = 0;

	while ( n ) {
		res += n % 10;
		n /= 10;
	}
	
	return res;
}

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int n;

	cin >> n;

	for ( int i = 1; i < n; i++ ) {
		if ( i + getSumOfEachDigit(i) == n )  {
			cout << i << endl;
			return 0;
		}
	}

	cout << 0 << endl;

    return 0;
}
