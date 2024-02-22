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
int num, target, cnt = 0;
vector<int> nums;
 
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */

void sequence(int head, int sum, vector<int> arr) {
	if ( head >= num ) {
		if ( sum == target && arr.size() ) {
			cnt ++;
		}
		return;
	}

	vector<int> newArr = arr;
	newArr.push_back(nums[head]);
	sequence(head+1, sum + nums[head], newArr);
	sequence(head+1, sum, arr);
}

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int temp;

	cin >> num >> target;

	for (int i = 0; i < num; i++) {
		cin >> temp;

		nums.push_back(temp);
	}

	vector<int> empty;
	sequence(0, 0, empty);

	cout << cnt << endl;

    return 0;
}