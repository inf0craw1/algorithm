#include <iostream>
#include <string>

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

bool isIncluding666(int n) {
	string s = to_string(n);

	for ( int i = 0; i <= s.size() - 3; i++ ) {
		if ( s[i] == '6' && s[i+1] == '6' && s[i+2] == '6') {
			return true;
		}
	}
	return false;
}

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);
	
	int n, num = 666;
	
	cin >> n;

	for ( int counter = 1; counter <= n; num ++ ) {

		if ( isIncluding666(num) ) {
			counter ++;
		}

	}

	cout << num-1 << endl;

    return 0;
}
