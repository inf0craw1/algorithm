#include <iostream>
#include <string>
#include <vector>

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
int isPalindrome(int n) {
	string s = to_string(n);
	int size = s.size();

	for ( int i = 0; i < size/2; i++ ) {
		if ( s[i] != s[size - i - 1] ) {
			return 0;
		}
	}
	return 1;
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int a, b;
	vector<bool> era(10000001, 0);
	vector<int> primeNumbers, palindromePrimeNumbers;
	ll cnt = 0;

	for ( int i = 2; i <= 10000000; i++ ) {
		if( era[i] ) continue;
		primeNumbers.push_back(i);
		if ( isPalindrome(i) ) {
			palindromePrimeNumbers.push_back(i);
		}
		
		for ( int j = i + i; j <= 10000000; j+=i ) {
			era[j] = true;
			cnt ++;
		}
	}

	cin >> a >> b;

	for ( int i = 0; palindromePrimeNumbers[i] <= b; i++ ) {
		if ( palindromePrimeNumbers[i] >= a ) {
			cout << palindromePrimeNumbers[i] << endl;
		}
	}
	cout << -1 << endl;

    return 0;
}
