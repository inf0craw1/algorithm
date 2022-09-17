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

	string a, b, res;
	int temp, carry = 0;

	cin >> a >> b;

	for ( int i = 0; i < max(a.length(), b.length()); i++ ) {

		temp = carry;
		if( i < a.length() ) temp += a[a.length() - i - 1] - '0';
		if( i < b.length() ) temp += b[b.length() - i - 1] - '0';
		carry = temp / 10;
		res = to_string(temp % 10) + res;
	}
	if ( carry ) res = to_string(carry) + res;

	cout << res << endl;
    return 0;
}
