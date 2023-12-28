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

int n, m;
 
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */

void sequence(vector<int> v) {
	if ( v.size() != 0 ) {
		if ( v.size() >= m ) {
			for ( auto vv:v ) {
				cout << vv << ' ';
			}
			cout << endl;
			return;
		}
	}
	int startNumber = 1;
	if ( v.size() != 0 ) {
		startNumber = v[v.size() - 1];
	}
	for ( int i = startNumber; i <= n; i++ ) {
		vector<int> newVec = v;
		newVec.push_back(i);
		sequence(newVec);
	}
	return;
}

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	cin >> n >> m;

	vector<int> empty;

	sequence(empty);

    return 0;
}
