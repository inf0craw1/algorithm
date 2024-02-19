#include <bits/stdc++.h>

#define debug if constexpr (local) std::cout
#define endl '\n'
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

#ifdef LOCAL
constexpr bool local = true;
#else
constexpr bool local = false;
#endif

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
typedef unsigned long long ull;

/* - GLOBAL VARIABLES ---------------------------- */
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
bool IsPrimeNumber(int n) {
	for ( int i = 2; i*i <= n; i++ ) {
		if ( n % i == 0 ) return 0;
	}
	return 1;
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int n; cin >> n;
	vector<int> curiousPrimeNumber = {2, 3, 5, 7};
	vector<int> onesDigit = {1, 3, 7, 9};
	
	while ( n > 1 ) {
		vector<int> nextDigitCuriousPrimeNumber;

		for ( auto c: curiousPrimeNumber ) {
			for ( auto o: onesDigit ) {
				int newNum = c*10 + o;
				if ( IsPrimeNumber(newNum) ) nextDigitCuriousPrimeNumber.push_back(newNum);
			}
		}

		curiousPrimeNumber = nextDigitCuriousPrimeNumber;
		n--;
	}

	for ( auto c: curiousPrimeNumber ) {
		cout << c << endl;
	}
	
    return 0;
}
