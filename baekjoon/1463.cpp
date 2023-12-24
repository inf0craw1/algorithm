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
vector<int> minis;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */

 void findMin(int cur, int step) {
	 if ( minis[cur] <= step ) return;
	 minis[cur] = step;
	 cout << cur << ' ' << step << endl;
	 if ( cur == 1 ) {
		 cout << "fin : " << step << endl;
		 minis[cur] = min(step, minis[cur]);
		 return;
	 }

	 if ( cur % 3 == 0 ) {
		 findMin(cur/3, step + 1);
	 }
	 if ( cur % 2 == 0 ) {
	 	findMin(cur/2, step + 1);
	 }
	 findMin(cur-1, step + 1);
}

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

	if constexpr (local) {
        freopen("./input.txt", "r", stdin);
	} 

	int n;

	cin >> n;
	minis.resize(n+1, 2e9);

	findMin(n, 0);

	int i = 0;
	for ( auto v: minis ) {
		cout << i++ << " : " << v << endl;
	}

	cout << minis[1] << endl;

    return 0;
}
