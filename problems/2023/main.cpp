#include <iostream>
#include <vector>
#include <cmath>
#include <set>

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
int n, cnt = 0;
set<int> primeNumbers;
vector<bool> era(100000000, false);
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
bool isCuriousPrimeNumber(int n) {
	while ( n >= 10 ) {
		n /= 10;
		if ( primeNumbers.find(n) == primeNumbers.end() ) return 0;
	}
	return 1;
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	for ( int i = 2; i < 100000000; i++) {
		if ( era[i] ) continue;
		
		if ( isCuriousPrimeNumber(i) ) {
			primeNumbers.insert(i);
		}
		for ( int j = i + i; j < 100000000; j+=i ) {
			era[j] = true;
			cnt ++;
		}
	}
	for ( auto p: primeNumbers ) {
		cout << p << ' ';
	}
	cout << endl;
	return 0;

	cin >> n;

	for ( auto p: primeNumbers ) {
		if ( pow(10, n) <= p ) break;
		if ( pow(10, n - 1) <= p ) {
			cout << p << endl;
		}
	}
    return 0;
}
