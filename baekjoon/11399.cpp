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
	vector<int> times;

	cin >> num;
	for ( int i = 0; i < num; i++ ) {
		cin >>temp;
		times.push_back(temp);
	}

	times.push_back(0);

	sort(all(times));

	for ( int i = 1; i <= num; i++ ) {
		times[i] += times[i - 1];
		res += times[i];
	}

	cout << res << endl;

    return 0;
}
