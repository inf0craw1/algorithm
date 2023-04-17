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
 
int numerator1, numerator2, denominator1, denominator2;
int a, b;

/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */

void checkAndSwap(void) {
	if ( a > b ) return;
	swap(a, b);
	return;
}

int leastCommonMultiple(int a, int b) {
	if ( a % b == 0 ) {
		return b;
	}
	leastCommonMultiple(a, b % a);
	return 0;
}

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);


	cin >> numerator1 >> denominator1 >> numerator2 >> denominator2;

	int commonDenominator = denominator1 * denominator2;
	int res;

	a = denominator1;
	b = denominator2;


	checkAndSwap();
	res = leastCommonMultiple(a, b);

	commonDenominator /= res;

	numerator1 *= commonDenominator / denominator1;
	numerator2 *= commonDenominator / denominator2;

	a = numerator1 + numerator2;
	b = commonDenominator;

	checkAndSwap();

	res = leastCommonMultiple(a, b);

	cout << (numerator1 + numerator2) / res << ' ' << commonDenominator / res << endl;
	

    return 0;
}
