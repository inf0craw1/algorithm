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
		auto temp = find(v.begin(), v.end()-1, v[v.size() - 1]);
		if ( temp != v.end()-1 ) return;
		
		if ( v.size() >= m ) {
			for ( auto vv:v ) {
				cout << vv << ' ';
			}
			return;
		}
	}
	for ( int i = 1; i <= n; i++ ) {
		vector<int> newVec = v;
		newVec.push_back(i);
		sequence(v);
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

	vector<int> test = {0, 1, 2, 3, 3};

	cout << ' ' << test.size() << ' ' << test.size() - 1 << ' ' << test[test.size() - 1] << endl;

	if ( find(test.begin(), (test.end() - 1), test[test.size() ]) == (test.end() - 1 )) {
		cout << "found!!" << endl;
	}

	vector<int> empty;

	sequence(empty);

    return 0;
}
