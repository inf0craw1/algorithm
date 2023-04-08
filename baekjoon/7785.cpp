#include <iostream>
#include <set>

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

	int n;
	string stat;
	set<string> s;

	cin >> n;

	for ( int i = 0; i < n; i++ ) {
		string temp;

		cin >> temp >> stat;

		if ( stat == "enter" ) {
			s.insert(temp);
		} else {
			s.erase(temp);
		}
	}

	for ( auto ss = s.rbegin(); ss != s.rend(); ss++ ) {
		cout << *ss << endl;
	}

    return 0;
}
