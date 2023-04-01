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

	int n, quarter, dime, nickel, penny;

	cin >> n;


	for ( int i = 0; i < n; i++ ) {
		int temp;
		
		cin >> temp;

		quarter = temp / 25;
		temp %= 25;
		dime = temp / 10;
		temp %= 10;
		nickel = temp / 5;
		temp %= 5;
		penny = temp;

		cout << quarter << ' ' << dime << ' ' << nickel << ' ' << penny << endl;

	}


    return 0;
}
