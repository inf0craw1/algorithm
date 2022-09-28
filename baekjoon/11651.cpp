#include <bits/stdc++.h>

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

bool comp(pair<int, int> a, pair<int,int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	} 

	return a.second < b.second;
}
 
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int num, tmp1, tmp2;
	vector<pair<int, int>> n;

	cin >> num;

	for ( int i = 0; i < num; i++ ) {
		cin >> tmp1 >> tmp2;
		n.push_back({tmp1, tmp2});
	}

	sort(n.begin(), n.end(), comp);

	for ( int i = 0; i < num; i++ ) {
		cout << n[i].first << ' ' << n[i].second << endl;
	}

    return 0;
}
