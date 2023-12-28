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
int num, mini = 2e9, maxi = -2e9;
vector<int> nums, ops;
 
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */

int getOperatedValue(int a, int b, int op) {
	switch (op) {
		case 0:
			return a + b;
			break;
		case 1:
			return a - b;
			break;
		case 2:
			return a * b;
			break;
		case 3:
			return a / b;
			break;
	}
	return 0;
}

void calculate(int head, int acc, vector<int> ops) {

	if ( head == num ) {
		maxi = max(maxi, acc);
		mini = min(mini, acc);
		return;
	}

	vector<int> restOps;

	for ( int i = 0; i < 4; i++ ) {
		if ( !ops[i] ) continue;

		restOps = ops;
		restOps[i]--;
		calculate(head + 1, getOperatedValue(acc, nums[head], i), restOps);
	}

	return;
}

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int temp;

	cin >> num;

	for ( int i = 0; i < num; i++ ) {
 		cin >> temp;
		nums.push_back(temp);
	}

	for ( int i = 0; i < 4; i++ ) {
		cin >> temp;
		ops.push_back(temp);
	}

	calculate(1, nums[0], ops);

	cout << maxi << endl << mini << endl;


    return 0;
}
