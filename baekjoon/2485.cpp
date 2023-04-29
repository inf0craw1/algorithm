#include <iostream>
#include <algorithm>
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

	ll n;
	ll greatestCommonDivisor = 1;
	vector<ll> v, vec, primeNumbers;
	vector<bool> SieveOfEratosthenes(32000, false);

	for ( ll i = 2; i * i <= 1000000000; i++ ) {
		if ( SieveOfEratosthenes[i] == false ) {
			primeNumbers.push_back(i);
			for ( ll j = i; j * j <= 1000000000; j += i ) {
				SieveOfEratosthenes[j] = true;
			}
		}
	}


	cin >> n;

	for ( ll i = 0; i < n; i++ ) {
		ll temp;

		cin >> temp;
		vec.push_back(temp);
	}

	for ( ll i = 1; i < vec.size(); i++ ) {
		ll temp = vec[i] - vec[i-1];

		v.push_back(temp);
	}

	sort(v.begin(), v.end());

	for ( ll i = 0; primeNumbers[i] * primeNumbers[i] <= v[v.size() - 1]; i++ ) {
		bool chk = true;
		for ( ll j = 0; j < n; j++ ) {
			if ( (ll)v[j]/greatestCommonDivisor % primeNumbers[i] != 0 ) {
				chk = false;	

				break;
			}
		}

		if ( chk ) {
			greatestCommonDivisor *= primeNumbers[i];
			i = -1;
		}

	}


	cout << ( vec[vec.size() - 1] - vec[0] ) / greatestCommonDivisor + 1 - n << endl;

    return 0;
}
