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
int num;
vector<int> nums;
 
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */

void getCombination(vector<int> vec) {

	if ( vec.size() == 6 ) {
		for ( auto v: vec ) {
			cout << nums[v] << ' ';
		}
		cout << endl;
		return;
	}

	for ( int i = vec.size() ? vec[vec.size() - 1] + 1 : 0; i < num; i++ ) {
		vector<int> newVec = vec;
		newVec.push_back(i);

		getCombination(newVec);
		
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
	vector<int> empty;
	
	for ( ;; ) {
		cin >> num;
		if ( num == 0 ) break;

		nums = empty;

		for ( int i = 0; i < num; i++ ) {
			cin >> temp;

			nums.push_back(temp);
		}

		getCombination(empty);
		cout << endl;
	}

    return 0;
}
