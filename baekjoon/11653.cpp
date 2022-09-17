#include <bits/stdc++.h>

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

	int n, i, j;
	bool era[3200] = {};
	vector<int> primes;

	cin >> n;

	if ( n == 1 ) return 0;

	for ( i = 2; i <= sqrt(3200); i++ ) {
		if ( era[i] ) continue;
		for ( j = i * 2; j <= 3200; j += i ) {
			era[j] = true;
		}
	}

	for ( i = 2; i <= 3200; i++ ) {
		if ( !era[i] ) primes.push_back(i);
	}

	for ( i = 0; n > 0 ; i++ ) {
		for ( j = 0; j < primes.size(); j++ ) {
			if ( n % primes[j] == 0 ) {
				cout << primes[j] << endl;
				if ( n == primes[j] ) return 0;
				n /= primes[j];
				break;
			}
		}
		if ( j == primes.size() ) break;
	}

	cout << n << endl;

    return 0;
}
