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

	int n, k, cnt = 0;
	vector<int> era;

	cin >> n >> k;

	era.resize(n+1, 0);

	for ( int i = 2; i <= n; i++ ) {
		if ( !era[i] ) {
			for ( int j = i; j <= n; j += i ) {
				if ( era[j] ) continue;
				era[j] = 1;
				cnt ++;
				if ( cnt == k ) {
					cout << j << endl;
					return 0;
				}
			}
		}
	}

	return 0;
}
