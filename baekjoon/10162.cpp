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

	int num;
	vector<int> times = {10, 60, 300};

	cin >> num;
	
	if ( num % 10 != 0 ) {
		cout << -1 << endl;
		return 0;
	}

	for ( int i = times.size() - 1; i >= 0; i-- ) {
		cout << num / times[i] << ' ';
		num %= times[i];
	}
	cout << endl;



    return 0;
}
