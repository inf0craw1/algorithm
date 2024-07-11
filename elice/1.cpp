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
ll GetScore(int num) {
	ll res = 0;

	while ( num ) {
		res += pow(10, num % 10 );
		num /= 10;
	}

	return res;
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int num; cin >> num;
	ll targetScore = GetScore(num);

	cout << targetScore << endl;
	
	for ( int i = num + 1; ; i++ ) {
		if ( GetScore(i) == targetScore ) {
			cout << i << endl;
			return 0;
		}
	}

    return 0;
}
