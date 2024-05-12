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
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	string str; cin >> str;
	int len = str.size();
	int oddCnt = 0, oddPos;
	vi alphaCnt = vi(27, 0);

	for ( auto s: str ) {
		alphaCnt[s-'A'] ++;
	}

	for ( int i = 0; i < 26; i++ ) {
		if ( alphaCnt[i] % 2 == 1 ) { 
			oddCnt ++;
			oddPos = i;
		}
		alphaCnt[i] /= 2;
	}

	if ( len % 2 == 0 && oddCnt != 0 || len % 2 == 1 && oddCnt > 1 ) {
		cout << "I'm Sorry Hansoo" << endl;
		return 0;
	}

	for ( int i = 0; i < 26; i++ ) {
		for ( int j = 0; j < alphaCnt[i]; j++ ) {
			cout << char(i + 'A');
		}
	}
	if ( oddCnt ) {
		cout << char(oddPos + 'A');
	}
	for ( int i = 25; i >= 0; i-- ) {
		for ( int j = 0; j < alphaCnt[i]; j++ ) {
			cout << char(i + 'A');
		}
	}
	cout << endl;
    return 0;
}
