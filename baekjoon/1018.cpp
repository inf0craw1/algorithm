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

	int x, y, mini = 10e8;

	cin >> y >> x;

	vector< vector<char> > v (y, vector<char> (x));

	for ( int i = 0; i < y; i++ ) {
		for ( int j = 0; j < x; j++ ) {
			cin >> v[i][j];
		}
	}

	for ( int i = 0; i <= y - 8; i++ ) {
		for ( int j = 0; j <= x - 8; j++ ) {

			int count = 0;

			for ( int k = i; k < i + 8; k++ ) {

				for ( int l = j; l < j + 8; l++ ) {
					if ( ( v[k][l] == 'B' && ( k + l ) % 2 == 0 ) || ( v[k][l] == 'W' && ( k + l ) % 2 == 1 ) )	 {
						count++;
					}
				}
			}

			mini = min( mini, min(count, 64 - count) );
		}
	}
	
	cout << mini << endl;


    return 0;
}
