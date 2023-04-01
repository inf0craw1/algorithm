#include <iostream>
#include <string>

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

	string str;
	ll res = 0, notation, currentMultiplier = 1;

	cin >> str >> notation;

	for ( auto c = str.rbegin(); c < str.rend(); c ++ ) {
		int temp;
		if ( isalpha(*c) ) {
			temp = *c - 'A' + 10;
		} else {
			temp = *c - '0';
		}
		res += temp * currentMultiplier;
		currentMultiplier *= notation;
	}
	cout << res << endl;

    return 0;
}
