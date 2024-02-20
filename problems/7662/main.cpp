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
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int testCases; cin >> testCases;


	for ( int z = 0; z < testCases; z++ ) {
		priority_queue<ll> maxQ, minQ;
		unordered_map<ll,ll> nMap;
		int commands; cin >> commands;
		
		for ( int k = 0; k < commands; k++ ) {
			char command; cin >> command;
			ll n; cin >> n;

			if ( command == 'I' ) {
				maxQ.push(n);
				minQ.push(n * -1);
				auto nFound = nMap.find(n);
				if ( nFound == nMap.end() ) {
					nMap.insert({n, 1});
					continue;
				}
				nFound->se ++;
				continue;
			}

			if ( n == 1 ) {
				while ( maxQ.size() ) {
					ll curTop = maxQ.top();
					maxQ.pop();
					auto nFound = nMap.find(curTop);
					if ( nFound->se == 0 ) continue;
					nFound->se --;
					break;
				}
				continue;
			}
			while ( minQ.size() ) {
				ll curTop = minQ.top() * -1;
				minQ.pop();
				auto nFound = nMap.find(curTop);
				if ( nFound->se == 0 ) continue;
				nFound->se --;
				break;
			}
		}

		ll maxi, isExist = 0;
		while ( maxQ.size() ) {
			ll curTop = maxQ.top();
			maxQ.pop();
			auto nFound = nMap.find(curTop);
			if ( nFound->se == 0 ) continue;
			maxi = nFound->fi;
			isExist = 1;
			break;
		}
		ll mini;
		while ( minQ.size() ) {
			ll curTop = minQ.top() * -1;
			minQ.pop();
			auto nFound = nMap.find(curTop);
			if ( nFound->se == 0 ) continue;
			mini = nFound->fi;
			break;
		}
		if ( !isExist) {
			cout << "EMPTY" << endl;
			continue;
		}
		cout << maxi << ' ' << mini << endl;
	}

    return 0;
}
