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
 
int num;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	cin >> num;

	int remain = 1000 - num;
	int cnt = 0;
	vector<int> coins = {500, 100, 50, 10, 5, 1};

	for ( int i = 0; i < coins.size(); i++ ) {
		cnt += remain / coins[i];
		remain %= coins[i];
	}

	cout << cnt << endl;



    return 0;
}
