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
int numberOfHouses, numberOfRoads;
int res = 2e9, resHouse1, resHouse2;
vector<vector<int>> connection, connectionTime;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
void VisitAll(int house, int time) {
	queue<pi> q;
	q.push(make_pair(house, 0));

	while ( q.size() ) {
		pi cur = q.front();
		int curHouse = cur.fi, curTime = cur.se;
		q.pop();

		for ( int i = 1; i <= numberOfHouses; i++ ) {
			if ( connection[curHouse][i] == 1 && connectionTime[house][i] > curTime + 1 ) {
				connectionTime[house][i] = curTime + 1;
				q.push(make_pair(i, curTime + 1));
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

	cin >> numberOfHouses >> numberOfRoads;
	connection.resize(numberOfHouses+1, vector<int> (numberOfHouses+1, 0));
	connectionTime.resize(numberOfHouses+1, vector<int> (numberOfHouses+1, 2e9));

	for ( int i = 0; i < numberOfRoads; i++ ) {
		int a, b; cin >> a >> b;

		connection[a][b] = 1;
		connection[b][a] = 1;
	}

	for ( int i = 1; i <= numberOfHouses; i++ ) {
		connectionTime[i][i] = 0;
		VisitAll(i, 0);
	}

	for ( int i = 1; i <= numberOfHouses - 1; i++ ) {
		for ( int j = i + 1; j <= numberOfHouses; j++ ) {
			int curRes = 0;
			for ( int k = 1; k <= numberOfHouses; k++ ) {
				curRes += min(connectionTime[i][k], connectionTime[j][k]);
			}

			if ( curRes < res ) {
				res = curRes;
				resHouse1 = i;
				resHouse2 = j;
			}
		}
	}

	cout << resHouse1 << ' ' << resHouse2 << ' ' << res * 2 << endl;
    return 0;
}
