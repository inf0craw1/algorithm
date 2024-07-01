#include <bits/stdc++.h>

#define debug if constexpr (local) std::cout
#define endl '\n'
#define fi first
#define se second
#define INF 0x7fffffff
#define LINF 0x7fffffffffffffff
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

#ifdef LOCAL
constexpr bool local = true;
#else
constexpr bool local = false;
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;

/* - GLOBAL VARIABLES ---------------------------- */
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int height, width, size; cin >> height >> width >> size;

	vector<vector<pi>> mtrx(height + 1, vector<pi>(width + 1, {0, 0}));

	for ( int i = 1; i <= height; i++ ) {

		for ( int j = 1; j <= width; j++ ) {
			char temp; cin >> temp;
			if ( temp == 'W' ) {
				mtrx[i][j].fi = mtrx[i-1][j].fi + mtrx[i][j-1].fi - mtrx[i-1][j-1].fi;
				mtrx[i][j].se = mtrx[i-1][j].se + mtrx[i][j-1].se - mtrx[i-1][j-1].se;
				continue;
			}
			
			if ( (i + j) % 2 == 0 ) {
				mtrx[i][j].fi = mtrx[i-1][j].fi + mtrx[i][j-1].fi - mtrx[i-1][j-1].fi + 1;
				mtrx[i][j].se = mtrx[i-1][j].se + mtrx[i][j-1].se - mtrx[i-1][j-1].se;
				continue;
			}
			mtrx[i][j].fi = mtrx[i-1][j].fi + mtrx[i][j-1].fi - mtrx[i-1][j-1].fi;
			mtrx[i][j].se = mtrx[i-1][j].se + mtrx[i][j-1].se - mtrx[i-1][j-1].se + 1;
		}
	}

	int mini = INF;
	int evenSize = size % 2 == 1 ? size*size/2+1 : size*size/2;
	int oddSize = size * size / 2;

	for ( int i = 1; i <= height-size+1; i++ ) {
		for ( int j = 1; j <= width-size+1; j++ ) {
			int accEven = mtrx[i + size - 1][j + size - 1].fi - mtrx[i-1][j + size - 1].fi - mtrx[i + size - 1][j-1].fi + mtrx[i-1][j-1].fi;
			int accOdd = mtrx[i + size - 1][j + size - 1].se - mtrx[i-1][j + size - 1].se - mtrx[i + size - 1][j-1].se + mtrx[i-1][j-1].se;
			int even = accEven + abs(oddSize - accOdd);
			int odd = abs(evenSize - accEven) + accOdd;
			int curMin = min(even, odd);

			mini = min(mini, curMin);
		}
	}

	cout << mini << endl;
    return 0;
}
