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

	int a, b, c;

	cin >> a >> b >> c;

	if ( a + b + c != 180 ) {
		cout << "Error" << endl;
	} else if ( a == 60 && b == 60 ) {
		cout << "Equilateral" << endl;
	} else if ( a == b || b == c || a == c ) {
		cout << "Isosceles" << endl;
	} else {
		cout << "Scalene" << endl;
	}


    return 0;
}
