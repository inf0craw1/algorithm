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

	vector<char> res;
	ll n;
	int notation;

	cin >> n >> notation;

	while ( n > 0 ) {
		int temp = n % notation;

		if ( temp >= 10 ) {
			res.push_back(temp - 10 + 'A');
		} else {
			res.push_back(temp + '0');
		}
		n /= notation;
	}

	for ( auto r = res.rbegin(); r < res.rend(); r++ ) {
		cout << *r;
	}

	cout << endl;

    return 0;
}
