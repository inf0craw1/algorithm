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
 
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	string s;
	int counter = 0;
	getline(cin, s);
	s = " " + s;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ' && (('a' <= s[i+1] && s[i+1] <= 'z') || ('A' <= s[i+1] && s[i+1] <= 'Z'))) {
			counter++;
		}
	}
	cout << counter << endl;
    return 0;
}
