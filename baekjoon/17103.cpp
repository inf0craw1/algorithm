#include <iostream>
#include <vector>
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

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int n;
	vector<int> v, primeNumbers;
	vector<bool> sieveOfEratosthenes(1000000, false);
	set<int> s;

	cin >> n;

	for ( int i = 0; i < n; i++ ) {
		int temp;

		cin >> temp;

		v.push_back(temp);
	}

	for ( int i = 2; i < 1000000; i++ ) {
		if ( sieveOfEratosthenes[i] == false )  {
			primeNumbers.push_back(i); 
			s.insert(i);

			for ( int j = i; j < 1000000; j += i ) {
				sieveOfEratosthenes[j] = true;
			}
		}
	}

	for ( int i = 0; i < n; i++ ) {
		int counter = 0;

		for ( int j = 0; primeNumbers[j] <= v[i]/2 ; j++ ) {
			if ( s.find(v[i] - primeNumbers[j]) != s.end() ) {
				counter++;
			}
		}
		cout << counter << endl;
	}

	

	
    return 0;
}
