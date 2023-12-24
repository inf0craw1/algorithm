#include <iostream>
#include <vector>
#include <string>

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

vector<int> fibo(41, 0);
vector<int> zeros(41, 0);
vector<int> ones(41, 0);
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */

int getFibo(int n) {
	if(fibo[n] != 0) return fibo[n];
	fibo[n] = getFibo(n-2) + getFibo(n-1);
	return fibo[n];
}

int getNumberOfNum(int cur, char target) {
	string temp = to_string(cur);
	int cnt = 0;

	for(auto s: temp) {
		if( s == target ) {
			cnt ++;
		}
	}
	return cnt;
}

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);
	fibo[0] = 1;
	fibo[1] = 1;
	fibo[2] = 2;

	int n;
	cin >> n;

	getFibo(41);
	cout << fibo[20] << endl;

	for ( int i = 1; i <= 40; i++ ) {
		zeros[i] = zeros[i-1] + getNumberOfNum(fibo[i],'0');
		ones[i] = ones[i-1] + getNumberOfNum(fibo[i], '1');
		cout << i << " : " << zeros[i] << ',' << ones[i] << endl;
	}


	int i = 0;
	for ( auto f: fibo ) {
		cout << i++ << " : " << f << endl;
	}
	cout << endl;

	for ( int i = 0; i < n; i++ ) {
		int temp;
		cin >> temp;
	}


    return 0;
}
