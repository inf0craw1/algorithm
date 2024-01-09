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

	int n, temp, cnt = 0;
	vector<int> era(1001, 0);

	era[1] = 1;

	cin >> n;

	for ( int i = 2; i <= 1000; i++) {
		if ( !era[i] ) {
			for ( int j = i + i; j <= 1000; j += i ) {
				era[j] = 1;
			}
		}
	}
	

	for ( int i = 0; i < n; i++ ) {
		cin >> temp;

		if ( !era[temp] ) {
			cnt ++;
		}
	}

	cout << cnt << endl;

    return 0;
}
