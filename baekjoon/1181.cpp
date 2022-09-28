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
struct Compare {
	bool operator() (const string &a, const string &b) const {
		if ( a.length() ==  b.length() ) return a < b;

		return a.length() < b.length();
	}
}; 
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	set<string, Compare> s;
	string temp;
	int num;

	cin >> num;

	for ( int i = 0; i < num; i++ ) {
		cin >> temp;
		s.insert(temp);
	}
	for (auto it = s.begin(); it != s.end(); it++ ) {
		cout << *it << endl;
	}
    return 0;
}
