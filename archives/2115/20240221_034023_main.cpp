#include <bits/stdc++.h>

#define debug if constexpr (local) std::cout
#define endl '\n'
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

#ifdef LOCAL
constexpr bool local = true;
#else
constexpr bool local = false;
#endif

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
typedef unsigned long long ull;

/* - GLOBAL VARIABLES ---------------------------- */
int height, width, res = 0;
vector<vi> mapp;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	char temp;

	cin >> height >> width;
	for ( int i = 0; i < height; i++ ) {
		vi tempRow;
		for ( int j = 0; j < width; j++ ) {
			cin >> temp;
			if ( temp == 'X' ) {
				tempRow.push_back(1);
				continue;
			}
			tempRow.push_back(0);
		}
		mapp.push_back(tempRow);
	}
	int cnt1 = 0, cnt2 = 0;
	for ( int j = 0; j < width-1; j++ ) {
		for ( int i = 0; i < height; i++ ) {
			if ( mapp[i][j] == 0 && mapp[i][j+1] == 1 ) {
				cnt1 ++;
				res += cnt2 / 2;
				cnt2 = 0;
				continue;
			}
			if ( mapp[i][j] == 1 && mapp[i][j+1] == 0 ) {
				cnt2 ++;
				res += cnt1 / 2;
				cnt1 = 0;
				continue;
			}
			res += cnt1 / 2;
			cnt1 = 0;
			res += cnt2 / 2;
			cnt2 = 0;
		}
	}
	cnt1 = 0;
	cnt2 = 0;
	
	for ( int i = 0; i < height-1; i++ ) {
		for ( int j = 0; j < width; j++ ) {
			if ( mapp[i][j] == 0 && mapp[i+1][j] == 1 ) {
				cnt1 ++;
				res += cnt2 / 2;
				cnt2 = 0;
				continue;
			}
			if ( mapp[i][j] == 1 && mapp[i+1][j] == 0 ) {
				cnt2 ++;
				res += cnt1 / 2;
				cnt1 = 0;
				continue;
			}
			res += cnt2 / 2;
			cnt2 = 0;
			res += cnt1 / 2;
			cnt1 = 0;
		}
	}

	cout << res << endl;

    return 0;
}
