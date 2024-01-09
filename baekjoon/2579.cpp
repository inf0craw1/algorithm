#include <iostream>
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
int num, maxi = 0;
vector<int> vec;
 
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */

void getStep(int idx, int continuousOne, int sum) {
	if ( idx >= num ) {
		if ( maxi < sum ) maxi = sum;
		return;
	}
	if ( continuousOne == 2 ) {
		getStep(idx + 2, 1, sum + vec[idx]);
		return;
	}

	getStep(idx + 2, 1, sum + vec[idx]);
	getStep(idx + 1, continuousOne + 1, sum + vec[idx]);

}

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	
	int temp;

	cin >> num;

	vec.resize(num, 0);

	for (int i = num-1; i >= 0; i--) {
		cin >> temp;
		vec[i] = temp;
	}

	getStep(0, 1, 0);

	cout << maxi << endl;

    return 0;
}
