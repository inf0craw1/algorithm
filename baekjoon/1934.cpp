#include <iostream>
#include <vector>
#include <map>
#include <set>

#define debug if constexpr (local) std::cout
#define endl '\n'
#define fi first
#define se second
#define all(x) x.begin(),x.end()

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

void addPrime(map<int, int>* s, int num) {
	auto foundElem = s->find(num);

	if ( foundElem != s->end() ) {
		foundElem->second ++;
		return;
	}

	s->insert({num, 1});

	return;
}

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int n;
	vector<bool> SieveOfEratosthenes(45001, true);
	set<int> primeSet;
	
	cin >> n;

	for (int i = 2; i <= 45000; i++) {
		if ( SieveOfEratosthenes[i] ) {
			primeSet.insert(i);
			for ( int j = i+i; j <= 45000; j+=i ) {
				SieveOfEratosthenes[j] = false;
			}
		}
	}

	for ( int i = 0; i < n; i++ ) {
		int a, b;
		map<int, int> ma, mb;

		cin >> a >> b;


		while ( primeSet.find(a) == primeSet.end() && a != 1 ) {
			for ( auto ss : primeSet) {
				if ( a % ss == 0 ) {
					addPrime(&ma, ss);
					a /= ss;
					break;
				}
			}
		}
		addPrime(&ma, a);

		while ( primeSet.find(b) == primeSet.end() && b != 1 ) {
			for ( auto ss: primeSet ) {
				if ( b % ss == 0 ) {
					addPrime(&mb, ss);
					b /= ss;
					break;
				}
			}
		}
		addPrime(&mb, b);

		map<int, int> resMap = ma;

		for ( auto mm: mb ) {
			auto foundKey = resMap.find(mm.first);

			if ( foundKey == resMap.end() ) {
				resMap.insert(mm);
				continue;
			}

			if ( foundKey->second < mm.second ) {
				foundKey->second = mm.second;
			}
		}

		ll res = 1;

		for ( auto mm: resMap ) {
			for ( int i = 0; i < mm.second; i++ ) {
				res *= mm.first;
			}
		}
		cout << res << endl;
	}

    return 0;
}
