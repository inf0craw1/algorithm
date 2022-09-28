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
struct USER {
	int index;
	int age;
	string name;
};
 
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */

bool comp(USER a, USER b) {
	if (a.age == b.age) {
		return a.index < b.index;
	}
	return a.age < b.age;
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int num, age;
	string name;
	vector<USER> user;

	cin >> num;

	for ( int i = 0; i < num; i++ ) {
		cin >> age >> name;
		USER temp = {i, age, name};
		user.push_back( temp );
	}
	sort(user.begin(), user.end(), comp);
	for ( int i = 0; i < num; i++ ) {
		cout << user[i].age << ' ' << user[i].name << endl;
	}
    return 0;
}
