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

void sequence(int num, vector<int> v) {

	if ( num != 0 ) {
		auto temp = find(v.begin(), v.end(), num);
		if ( temp != v.end() ) return;
		
		if ( v.size() >= m-1 ) {
			for ( auto vv:v ) {
				cout << vv << ' ';
			}
			cout << num << endl;
			return;
		}
		v.push_back(num);
	}
	for ( int i = 1; i <= n; i++ ) {
		sequence(i, v);
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

	sequence(0, empty);

    return 0;
}
