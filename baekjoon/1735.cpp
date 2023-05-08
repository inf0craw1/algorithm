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

	int a, b, c, d;
	int resNumerator, resDenominator;
	vector<bool> sieveOfEratosthenes(175, false);
	vector<int> primeNumbers;
	int tempCommon = 1, common; 

	cin >> a >> b >> c >> d;

	for ( int i = 2; i < 175; i++ ) {
		if ( !sieveOfEratosthenes[i] ) {
			primeNumbers.push_back(i);

			for ( int j = i; j < 175; j += i  ) {
				sieveOfEratosthenes[j] = true;
			}
		}
	}


	while ( 1 ) {
		bool chk = false;
		for ( int i = 0; primeNumbers[i] < min(b, d); i++ ) {
			if ( b % primeNumbers[i] == 0 && d % primeNumbers[i] == 0 ) {
				tempCommon *= primeNumbers[i];

				b /= primeNumbers[i];
				d /= primeNumbers[i];

				chk = true;
			}
		}

		if ( !chk ) {
			break;
		}
	}
	

	common = tempCommon * b * d;
	
	a *= common / b;
	c *= common / d;


	resNumerator = a + c;
	resDenominator = common;

	common = 1;
	
	while (1) {
		bool chk = false;
		for ( int i = 0; primeNumbers[i] < resDenominator; i++ ) {
			if ( resNumerator % primeNumbers[i] == 0 && resDenominator % primeNumbers[i] == 0 ) {
				common *= primeNumbers[i];
				resNumerator /= primeNumbers[i];
				resDenominator /= primeNumbers[i];
				chk = true;
			}
		}
		if ( !chk ) {
			break;
		}
	}
	

	cout << resNumerator << ' '  << resDenominator << endl;



   return 0;
}
