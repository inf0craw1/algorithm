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

	int a, b, res = 0, mini = 2e9;
	bool era[10001] = {};
	era[0] = true;
	era[1] = true;

	cin >> a >> b;

	for ( int i = 2; i <= sqrt(10000); i++ ) {
		if ( era[i] ) continue;
		for (int j = i * 2; j <= 10000; j += i ) {
			era[j] = true;
		}
	}

	for ( int i = b; i >= a; i-- ) {
		if ( !era[i] ) {
			res += i;
			mini = i;
		}			
	}

	if ( res == 0 ) {
		cout << -1 << endl;
		return 0;
	}

	cout << res << endl << mini << endl;
    return 0;
}
