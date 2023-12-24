#include <iostream>
#include <algorithm>
#include <vector>

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
vector<int> minis; 
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	minis.resize(n+1, 2e9);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	minis[1] = 0;

	for ( int i = 1; i <= n; i++ ) {
		if ( i+1 <= n && minis[i]+1 < minis[i+1] ) { // plus 1
			minis[i+1] = minis[i] + 1;
		}
		if ( i*2 <= n && minis[i]+1 < minis[i*2] ) {
			minis[i*2] = minis[i] + 1;
		}
		if ( i*3 <= n && minis[i]+1 < minis[i*3] ) {
			minis[i*3] = minis[i] + 1;
		}
	}
	
	cout << minis[n] << endl;

    return 0;
}
