#include <iostream>
#include <algorithm>
#include <map>

#define debug if constexpr (local) std::cout
#define endl '\n'
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define pii pair<int, int>

#ifdef LOCAL
constexpr bool local = true;
#else
constexpr bool local = false;
#endif

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

/* - GLOBAL VARIABLES ---------------------------- */
int n, s, e;
map<pii, int> dpMap;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
int GetCombination(pii nodes) {
	if ( nodes.fi == 1 ) return nodes.se;
	if ( nodes.fi == nodes.se ) return 1;
	auto findIter = dpMap.find(nodes);

	if ( findIter != dpMap.end() ) {
		return findIter->se;
	}
	
	int res = 0;
	for ( int i = nodes.se-1; i >= nodes.fi-1; i-- ) {
		res += GetCombination(make_pair(nodes.fi-1, i));
	}
	dpMap.insert({nodes, res});
	return res;
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int n;

	cin >> n;

	for ( int i = 0; i < n; i++ ) {
		cin >> s >> e;
		cout << GetCombination(make_pair(s, e)) << endl;
	}

    return 0;
}
