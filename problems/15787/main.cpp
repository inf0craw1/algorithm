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
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int trains, operations; cin >> trains >> operations;
	vi flag = {1}, train(trains);

	for ( int i = 1; i < 20; i++ ) {
		flag.push_back(flag[i-1] * 2);
	}

	for ( auto f: flag ) {
		bitset<20> temp(f);
		cout << temp << endl;
	}

	for ( int i = 0; i < operations; i++ ) {
		cout << "----- i = " << i << endl;
		for ( auto t: train ) {
			bitset<20> temp(t);
			cout << temp << endl;
		}
		int op, targetTrain, targetSeat; cin >> op >> targetTrain;

		if ( op < 3 ) cin >> targetSeat;

		if ( op == 1 ) {
			train[targetTrain-1] &= flag[targetSeat-1];
			bitset<20> tt(train[targetTrain-1]);
			
			continue;
		}
		if ( op == 2 ) {
			train[targetTrain-1] &= ~flag[targetSeat-1];
			bitset<20> tt(train[targetTrain-1]);
			
			continue;
		}
		if ( op == 3 ) {
			train[targetTrain-1] <<= 1;
			bitset<20> tt(train[targetTrain-1]);
			continue;
		}
		train[targetTrain-1] >>= 1;
		bitset<20> tt(train[targetTrain-1]);

		cout << tt << endl;		
			

	
	}

	set<int> res;

	for ( auto t: train ) {
		cout << t << ' ';
		res.insert(t);
	}
	cout << res.size() << endl;

    return 0;
}
