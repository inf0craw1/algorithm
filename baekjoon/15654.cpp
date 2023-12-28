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
vector<int> arr;
 
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */

void sequence(vector<int> v) {
	if ( v.size() != 0 ) {
		auto temp = find(v.begin(), v.end()-1, v[v.size() - 1]);
		if ( temp != v.end()-1 ) return;
		
		if ( v.size() >= m ) {
			for ( auto vv:v ) {
				cout << arr[vv - 1] << ' ';
			}
			cout << endl;
			return;
		}
	}
	for ( int i = 1; i <= n; i++ ) {
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

	int temp;

	cin >> n >> m;

	for ( int i = 0; i < n ; i++ ) {
		cin >> temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());

	vector<int> empty;

	sequence(empty);

    return 0;
}
