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

	int n, num;
	bool era[10001] = {true, true, };
	
	for ( int i = 2; i <= 100; i++ ) {
		if ( era[i] ) continue;
		for (int j = i * 2; j <= 10000; j += i ) {
			era[j] = true;
		}
	}

	cin >> num;
	
	for ( int i = 0; i < num; i++ ) {
		cin >> n;

		for ( int i = n / 2 ; i >= 2 ; i-- ) {
			if ( !era[i] && !era[n-i] ) {
				cout << i << ' ' << n - i << endl;
				break;
			} 
		}
	}

    return 0;
}
