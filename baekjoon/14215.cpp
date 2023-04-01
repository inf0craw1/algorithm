#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

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

	vector<int> v;
	int temp;

	for ( int i = 0; i < 3; i++ ) {
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.rbegin(), v.rend());

	if ( v[0] < v[1] + v[2] ) {
		cout << accumulate(v.begin(), v.end(), 0) << endl;
	} else {
		cout << ( v[1] + v[2] ) * 2 - 1 << endl;
	}

    return 0;
}
