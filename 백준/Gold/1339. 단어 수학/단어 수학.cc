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

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int n; cin >> n;
	int res = 0;
	vi alphaScore(27, 0);

	for ( int i = 0; i < n; i++ ) {
		string str; cin >> str;
		int len = str.size();
		int digit = pow(10, len-1);

		for ( int j = 0; j < len; j++, digit/=10 ) alphaScore[str[j] - 'A'] += digit;
	}
	sort(rall(alphaScore));

	for( int i = 0, d = 9; i < 10; i++, d-- ) {
		res += alphaScore[i] * d;
	}

	cout << res << endl;

    return 0;
}
