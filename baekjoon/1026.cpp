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
 
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int num, temp, res = 0;
	vector<int> a, b;

	cin >> num;

	for ( int i = 0; i < num; i++ ) {
		cin >> temp;
		a.push_back(temp);
	}

	for ( int i = 0; i < num; i++ ) {
		cin >> temp;
		b.push_back(temp);
	}

	sort(a.begin(), a.end());
	sort(b.rbegin(), b.rend());

	for ( int i = 0; i < num; i++ ) {

		res += a[i] * b[i];
	}

	cout << res << endl;

    return 0;
}
