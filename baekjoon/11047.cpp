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

	int num, remain, temp, cnt = 0;
	vector<int> coins;

	cin >> num >> remain;

	for ( int i = 0; i < num; i++ ) {
		cin >> temp;
		coins.push_back(temp);
	}

	for ( int i = coins.size() - 1; i >= 0; i-- ) {
		cnt += remain / coins[i];
		remain %= coins[i];
	}

	cout << cnt << endl;

    return 0;
}
