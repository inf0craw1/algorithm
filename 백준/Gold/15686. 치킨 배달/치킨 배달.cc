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
int n, remainChicken, allChicken, res = inf;
set<pi> combination;
vector<pi> houses, chickens;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
void GetChickenDistance() {
	int dis = 0;
	for ( int i = 0; i < houses.size(); i++ ) {
		int mini = inf;
		for ( auto c: combination ) {
			mini = min(mini, (int)(abs(houses[i].fi - c.fi) + abs(houses[i].se - c.se)));
		}
		dis += mini;
	}
	res = min(res, dis);
}
void MakeCombination(int num, int count) {
	if ( count > remainChicken ) return;
	if ( count == remainChicken ) {
		GetChickenDistance();
		return;
	}
	if ( num == allChicken ) return;
	MakeCombination(num+1, count);
	combination.insert(chickens[num]);
	MakeCombination(num+1, count+1);
	combination.erase(chickens[num]);
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	cin >> n >> remainChicken;

	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < n; j++ ) {
			int temp; cin >> temp;
			if ( temp == 0 ) continue;
			if ( temp == 1 ) {
				houses.push_back(make_pair(i, j));
				continue;
			}
			chickens.push_back(make_pair(i, j));
		}
	}

	allChicken = chickens.size();

	MakeCombination(0, 0);

	cout << res << endl;

    return 0;
}
