#include <bits/stdc++.h>

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

	int num, temp, counter = 0;
	int avg2 = 0, avg3 = -1, mini = 2e9, maxi = -2e9, maxFreqIndex = 0;
	double avg1 = 0;
	int n[8002] = {};

	cin >> num;

	for ( int i = 0; i < num; i++ ) {
		cin >> temp;
		temp += 4000;
		avg1 += temp;
		mini = min( mini, temp );
		maxi = max( maxi, temp );
		n[temp]++;
		if ( n[maxFreqIndex] < n[temp] ) maxFreqIndex = temp;
	}

	for ( int i = mini; i <= maxi ; i++ ) {
		counter += n[i];
		if ( counter >= num/2+1 ) {
			avg2 = i;
			break;
		}
	}
	for( int i = mini; i <= maxi; i++ ) {
		if ( n[maxFreqIndex] == n[i] ) {
			if ( avg3 != -1 ) {
				avg3 = i;
				break;
			}
			avg3 = i;
		}
	}

	cout << round(avg1/num) - 4000 << endl << avg2 - 4000 << endl << avg3 - 4000 << endl << maxi - mini << endl;

    return 0;
}
