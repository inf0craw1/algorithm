#include <iostream>
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
int width, height, remainTomatoes = 0, temp, maxi = 0;
vector<vector<int>> mapp;
vector<pii> directions = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
queue<pair<pii, int>> q;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
bool IsSafe(pii pos) {
	if ( pos.fi < 0 || pos.fi >= height || pos.se < 0 || pos.se >= width ) return 0;
	return 1;
}
void enripenTomatoes() {
	while ( q.size() ) {
		pair<pii, int> cur = q.front();
		pii curPos = cur.fi;
		int curDay = cur.se;
		q.pop();

		maxi = max(maxi, curDay);

		for ( auto d: directions ) {
			pii newPos = make_pair(curPos.fi + d.fi, curPos.se + d.se);
			if ( IsSafe(newPos) && mapp[newPos.fi][newPos.se] == 0 ) {
				q.push(make_pair(newPos, curDay + 1));
				mapp[newPos.fi][newPos.se] = 1;
				remainTomatoes --;
			}
		}
	}
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	cin >> width >> height;

	for ( int i = 0; i < height; i++ ) {
		vector<int> tempRow;
		for ( int j = 0; j < width; j++ ) {
			cin >> temp;
			tempRow.push_back(temp);
			if ( temp == 0 ) remainTomatoes++;
			if ( temp == 1 ) {
				q.push(make_pair(make_pair(i, j), 0));
			}
		}
		mapp.push_back(tempRow);
	}

	enripenTomatoes();

	cout << (remainTomatoes ? -1 : maxi) << endl;

    return 0;
}
