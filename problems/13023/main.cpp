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
int vertices, edges;
vector<vi> mapp;
vi isVisit;
bool res = 0;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
void ChkFriendship(int curVertice, int len) {

	if ( res || len == 5 ) {
		res = 1; 
		return;
	}

	for ( auto m: mapp[curVertice] ) {
		if ( !isVisit[m] ) {
			isVisit[m] = 1;
			ChkFriendship(m, len + 1);
			isVisit[m] = 0;
		}
	}
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	cin >> vertices >> edges;

	mapp.resize(vertices, vi (0, 0));

	for ( int i = 0; i < edges; i++ ) {
		pi temp; cin >> temp.fi >> temp.se;

		mapp[temp.fi].push_back(temp.se);
		mapp[temp.se].push_back(temp.fi);
	}

	for ( int i = 0; i < vertices; i++ ) {

		isVisit.clear();
		isVisit.resize(vertices, 0);
		isVisit[i] = 1;
		ChkFriendship(i, 1);
	}

	cout << res << endl;


    return 0;
}
