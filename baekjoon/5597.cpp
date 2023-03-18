#include <iostream>

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

	int num, counter = 0;
	bool arr[31] = {false};

	for ( int i = 0; i < 28; i++ ) {
		cin >> num;
		arr[num] = true;
	}

	for ( int i = 1; i <= 30 && counter < 2; i++ ) {
		if ( !arr[i] ) {
			cout << i << endl;
			counter++;
		}
	}

    return 0;
}
