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

	int a, b;
	bool era[1000001] = {true, true, };

	cin >> a >> b;

	for ( int i = 2; i <= 1000; i++ ) {
		if ( era[i] ) continue;
		for (int j = i * 2; j <= 1000000; j += i ) {
			era[j] = true;
		}
	}

	for ( int i = a; i <= b; i++ ) {
		if ( !era[i] ) {
			cout << i << endl;
		}			
	}

    return 0;
}
