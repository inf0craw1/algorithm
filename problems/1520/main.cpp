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

	for ( int i = 0; i < height; i++ ) {
		vi temp_row;
		for ( int j = 0; j < width; j++ ) {
			int temp; cin >> temp;
			temp_row.push_back(temp);
		}
		mapp.push_back(temp_row);
		dp.push_back(vi(width, 0));
	}

	int res = 0;
	queue<pi> q;
	
	q.push(make_pair(0, 0));

	while ( q.size() ) {
		pi cur = q.front();
		q.pop();

		if ( cur.fi == height - 1 && cur.se == width - 1 ) {
			res ++;
			continue;
		} 

		for ( auto d: directions ) {
			pi newPos = make_pair(cur.fi + d.fi, cur.se + d.se);
			if ( !IsSafe(newPos) ) continue;
			if ( mapp[cur.fi][cur.se] > mapp[newPos.fi][newPos.se] ) {
				q.push(newPos);
			}
		}
	}

	cout << res << endl;



    return 0;
}
