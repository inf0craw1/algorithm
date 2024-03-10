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
vector<char> operators;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */ 
bool IsZero() {
	int curNum = operators.size() - 1, tempNum = curNum + 1, digit = 1, res = 0;
	for ( int i = operators.size() - 2 ; i >= 0; i--, curNum-- ) {
		if ( operators[i] == ' ' ) {
			digit *= 10;
		}
		else if ( operators[i] == '+' ) {
			res += tempNum;
			tempNum = 0;
			digit = 1;
		}
		else {
			res -= tempNum;
			tempNum = 0;
			digit = 1;
		}
		tempNum += curNum * digit;
	}
	res += tempNum;
	
	return res == 0;
}
void GetCombinations(int n, int curLen) {
	if ( curLen == n ) {
		if ( IsZero() ) {
			for ( int i = 1; i <= n; i++ ) {
				cout << i << operators[i-1];
			}
			cout << n+1 << endl;
		}
		
		return;
	}

	operators[curLen] = ' ';
	GetCombinations(n, curLen+1);
	operators[curLen] = '+';
	GetCombinations(n, curLen+1);
	operators[curLen] = '-';
	GetCombinations(n, curLen+1);
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int tcs; cin >> tcs;

	for ( int z = 0; z < tcs; z++ ) {
		int maxNum; cin >> maxNum;

		operators.clear();
		operators.resize(maxNum, ' ');
		GetCombinations(maxNum-1, 0);
		cout << endl;
	}

    return 0;
}
