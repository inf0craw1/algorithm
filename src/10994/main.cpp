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
int n, sizeOfMap;
vector<vector<char>> mapp;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
void makeStarBox(int s, int e) {
	if ( s == e ) {
		mapp[s][e] = '*';
		return;
	}
	for ( int i = s; i <= e; i++ ) {
		mapp[s][i] = '*';
		mapp[e][i] = '*';
		mapp[i][s] = '*';
		mapp[i][e] = '*';
	}

	makeStarBox(s + 2, e - 2);
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	cin >> n;
	sizeOfMap = 4 * n - 3;

	mapp.resize(sizeOfMap, vector<char> (sizeOfMap, ' '));

	makeStarBox(0, sizeOfMap - 1);
	
	for ( auto row: mapp ) {
		for ( auto r: row ) {
			cout << r;
		}
		cout << endl;
	}

    return 0;
}
