#include <bits/stdc++.h>

#define debug if constexpr (local) std::cout
#define endl '\n'
#define fi first
#define se second
#define INF 0x7fffffff
#define LINF 0x7fffffffffffffff
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

#ifdef LOCAL
constexpr bool local = true;
#else
constexpr bool local = false;
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
/* - GLOBAL VARIABLES ---------------------------- */
 
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
bool IsPrimeNumber(ll num) {
	for ( int i = 2; i*i <= num; i++ ) {
		if ( num%i == 0 ) return 0;
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
	vi possibleNums(n); for ( auto &x: possibleNums ) cin >> x;
	vi curNums = possibleNums;

	for ( int i = 0; i < 10; i++ ) {
		vi newNums;
		for ( auto nn: curNums ) {
			for ( auto p: possibleNums ) {
				ll newNum = nn * 10 + p;
				if ( !IsPrimeNumber(newNum) ) {
					cout << "YES" << endl << newNum << endl;
					return 0;
				}

				newNums.push_back(newNum); 
			}
		}
		curNums = newNums;
	}

	cout << "NO" << endl;
	

    return 0;
}
