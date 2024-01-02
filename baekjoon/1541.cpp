#include <iostream>
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
 
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	string str;
	int chkIsMinus = 0, res = 0, curNum = 0;


	cin >> str;

	for ( int i = 0; i <= str.size(); i++ ) {
		if ( i == str.size() || str[i] == '+' || str[i] == '-') {
			if ( chkIsMinus ) {
				curNum *= -1;
			}
			res += curNum;
			curNum = 0;
			
			if ( str[i] == '-' ) chkIsMinus = 1;
			continue;
		}
		curNum *= 10;
		curNum += str[i] - '0';
	}

	cout << res << endl;

    return 0;
}
