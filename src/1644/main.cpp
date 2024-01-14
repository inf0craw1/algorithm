#include <iostream>
#include <vector>
#include <map>

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

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int n;
	ll res = 0, sum = 0;
	vector<int> era, primeNumbers = {0};
	map<int, int> continuousSum = {{0, 0}};

	cin >> n;
	
	era.resize(n+1, 0);

	for ( int i = 2; i <= n; i++ ) {
		if ( era[i] ) continue;
		primeNumbers.push_back(i);
		for ( int j = i + i; j <= n; j += i ) {
			era[j] = 1;
		}
	}

	for ( auto pp: primeNumbers ) {
		sum += pp;
	}
	for ( int i = 1; i < primeNumbers.size(); i++ ) {
		vector<int> shouldRemove;
		
		for ( auto iter = continuousSum.begin(); iter != continuousSum.end(); iter ++ ) {
			iter->se = iter->se - primeNumbers[i - iter->fi] + primeNumbers[i];
			if ( iter->se >= n ) {
				if ( iter->se == n ) {
					//cout << "found i: " << i << ", prime.i: " << primeNumbers[i] << ", iter->fi: " << iter->fi << ", iter->se: " << iter->se << endl;
					 res++; 
				}
				shouldRemove.push_back(iter->fi);
			}
		}

		auto prevSum = continuousSum.find(i-1);

		if ( i <= 10000 && prevSum != continuousSum.end() ) {
			continuousSum.insert(make_pair(i, prevSum->se+2));
			if ( prevSum->se+2 == n ) res++;
		}
		for ( auto s: shouldRemove ) {
			continuousSum.erase(s);
		}

	}
	cout << res << endl;

    return 0;
}
