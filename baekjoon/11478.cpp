#include <iostream>
#include <cstring>
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

	string s;
	set<string> st;

	cin >> s;

	for ( int i = 0; i < s.length(); i++ ) {
		for ( int j = 0; j < s.length() - i ; j++ ) {
			string ss = s.substr(j, i + 1);
			
			st.insert(ss);
		}
	}

	cout << st.size() << endl;

    return 0;
}
