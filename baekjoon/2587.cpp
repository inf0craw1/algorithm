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
 
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	vector<int> v(6, 0);
	int avg = 0;

	for ( int i = 0; i < 5; i++ ) {
		cin >> v[i];
		avg += v[i];
	}

	for ( int i = 0 ; i < 5; i++ ) {

		for ( int j = i; j < 5; j++ ) {
			if ( v[i] > v[j] ) {
				int temp = v[i];

				v[i] = v[j];
				v[j] = temp;
			}
		}
	}

	cout << avg/5 << endl << v[2] << endl;

    return 0;
}
