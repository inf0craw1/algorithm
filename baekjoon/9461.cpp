#include <iostream>
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
vector<ull> vec(102, 0);
vector<ull> presets = {0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9};
 
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */

ull getTriangle(int n) {
	if ( vec[n] ) {
		return vec[n];
	}
	vec[n] = getTriangle(n-1) + getTriangle(n-5);

	return vec[n];
}

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

	for ( int i = 0; i < presets.size(); i++ ) {
		vec[i] = presets[i];
	}

	if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);
  

	int n, temp;
	ull res;

	cin >> n;

	for ( int i = 0; i < n; i++ ) {
		cin >> temp;

		res = getTriangle(temp);
		cout << res << endl;
		
	}

    return 0;
}
