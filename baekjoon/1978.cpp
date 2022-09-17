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

	int n, temp, res = 0;
	bool era[1001] = {};
	era[0] = true;
	era[1] = true;

	cin >> n;

	for ( int i = 2; i <= sqrt(1000); i++ ) {
		if ( era[i] ) continue;
		for (int j = i * 2; j <= 1000; j += i ) {
			era[j] = true;
		}
	}

	for ( int i = 0; i < n; i++ ) {
		cin >> temp;
		if ( !era[temp] ) res++;
	}

	cout << res << endl;
    return 0;
}
