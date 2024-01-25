#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

#define debug if constexpr (local) std::cout
#define endl '\n'
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define pii pair<int, int>

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
bool IsSafe(pii pos, int n, int m) {
	if ( pos.fi < 0 || pos.fi >= n || pos.se < 0 || pos.se >= m ) return 0;
	return 1;
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int n, m;
	vector<vector<int>> mapp;
	vector<pii> directions = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
	queue<pair<pii, int>> q;
	string row;

	cin >> n >> m;

	for ( int i = 0; i < n; i++ ) {
		vector<int> tempRow;
		cin >> row;

		for ( int j = 0; j < m; j++ ) {
			if ( row[j] == '1' ) {
				tempRow.push_back(0);
				continue;
			}
			tempRow.push_back(1);
		}
		mapp.push_back(tempRow);
	}
	
	mapp[0][0] = 1;
	q.push(make_pair(make_pair(0, 0), 1));
	
	while ( q.size() ) {
		
		pair<pii, int> cur = q.front();
		pii curPos = cur.fi;
		int curStep = cur.se; 

		q.pop();

		for ( auto d: directions ) {
			pii newPos = make_pair( curPos.fi + d.fi, curPos.se + d.se );
			if ( !IsSafe(newPos, n, m) ) continue;
			if ( mapp[newPos.fi][newPos.se] == 1 ) continue;
			if ( newPos.fi == n - 1 && newPos.se == m - 1 ) {
				cout << curStep + 1 << endl;
				return 0;
			}
			mapp[newPos.fi][newPos.se] = 1;
			q.push(make_pair(newPos, curStep + 1));
		}
	}

    return 0;
}
