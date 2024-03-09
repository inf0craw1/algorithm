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
int width, height;
vector<vi> mapp, dp;
vector<pi> directions = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
bool IsSafe(pi pos) {
	if ( pos.fi < 0 || pos.fi >= height || pos.se < 0 || pos.se >= width ) return 0;
	return 1;
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	cin >> height >> width;
	dp.resize(height, vi (width, 0));
	dp[0][0] = 1;

	for ( int i = 0; i < height; i++ ) {
		vi tempRow;
		for ( int j = 0; j < width; j++ ) {
			int temp; cin >> temp;
			tempRow.push_back(temp);
		}
		mapp.push_back(tempRow);
	}

	int res = 0;
	queue<pi> q;
	q.push(make_pair(0, 0));

	while ( q.size() ) {
		pi curPos = q.front();
		q.pop();
		if ( curPos.fi == height - 1 && curPos.se == width - 1 ) res ++;
		int curNum = mapp[curPos.fi][curPos.se];

		for ( auto d: directions ) {
			pi newPos = make_pair(curPos.fi + d.fi, curPos.se + d.se);
			if ( !IsSafe(newPos) ) continue;
			if ( mapp[newPos.fi][newPos.se] < curNum ) q.push(newPos);
		}
	}

	cout << res << endl;

    return 0;
}
