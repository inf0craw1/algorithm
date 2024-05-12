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
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
bool IsSafe(pi pos) {
	if ( pos.fi < 1 || pos.se < 1 || pos.fi > height || pos.se > width ) return 0;
	return 1;
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	cin >> height >> width;

	priority_queue<pi> pq;
	pq.push(make_pair(-height, -width));
	unordered_set<int> visitedCol;
	vector<pi> directions = {{-2, 1}, {2, 1}, {-1, 2}, {1, 2}};
	int curCol = 1;


	while ( 1 ) {
		pi curFront = pq.front();
		pi curPos = make_pair(-curFront.fi, -curFront.se);
		pq.pop();
		if ( curCol =  )
		if ( curCol != curPos.se ) {
			res += visitedCol.size();
			visitedCol.clear();
		}

		for ( auto d: directions ) {
			pi newPos = make_pair(curPos.fi + d.fi, curPos.se + d.se);
			if ( IsSafe(newPos) ) {
				
			}
		}
		
		


	}

    return 0;
}
