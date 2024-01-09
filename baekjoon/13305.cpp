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

	ull num, temp, mini = 2e9, res = 0;
	vector<ull> distance, price;

	cin >> num;
	for ( int i = 0; i < num - 1; i++ ) {
		cin >> temp;
		distance.push_back(temp);
	}
	for ( int i = 0; i < num; i++ ) {
		cin >> temp;
		price.push_back(temp);
	}

	for ( int i = 0; i < num; i++ ) {
		mini = min(mini, price[i]);
		res += mini * distance[i];
	}

	cout << res << endl;

    return 0;
}
