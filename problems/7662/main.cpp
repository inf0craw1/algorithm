#include <bits/stdc++.h>

#define debug if constexpr (local) std::cout
#define endl '\n'
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

#ifdef LOCAL
constexpr bool local = true;
#else
constexpr bool local = false;
#endif

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
typedef unsigned long long ull;

/* - GLOBAL VARIABLES ---------------------------- */
priority_queue<int> maxQ, minQ;
unordered_map<int, int> maxDeletedList, minDeletedList;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
void PushDeletedList(int target, int type) {
	if ( type == 1 ) {
		auto foundMap = maxDeletedList.find(target);
		if ( foundMap == maxDeletedList.end() ) {
			maxDeletedList.insert({target, 1});
			return;
		}
		foundMap->se ++;
		return;
	}
	auto foundMap = minDeletedList.find(target);
	if ( foundMap == minDeletedList.end() ) {
		minDeletedList.insert({target, 1});
		return;
	}
	foundMap->se ++;
	return;
}
ll PopQueue(int dir) {
	if ( dir == 1 ) {
		while ( maxQ.size() ) {
			int popNum = maxQ.top();
			maxQ.pop();
			auto foundPopNum = maxDeletedList.find(popNum);

			if ( foundPopNum == maxDeletedList.end() || foundPopNum->se <= 0 ) {
				return popNum;
			}
			foundPopNum->se --;
		}
		return linf;
	}
	while ( minQ.size() ) {
		int popNum = minQ.top() * -1;
		minQ.pop();
		auto foundPopNum = minDeletedList.find(popNum);

		if ( foundPopNum == minDeletedList.end() || foundPopNum->se <= 0 ) {
			return popNum;
		}
		foundPopNum->se --;
	}
	return linf;
}
void Print() {
	cout << "---------------------" << endl;
	priority_queue<int> miniQ = minQ, maxiQ = maxQ;
	cout << "minQ: ";
	while ( miniQ.size() ) {
		cout << miniQ.top() * -1 << ' ';
		miniQ.pop();
	}
	cout << endl << "minDeletedList: ";
	for ( auto mm: minDeletedList ) {
		cout << mm.fi << ',' << mm.se << ' ';
	}
	cout << endl << "maxQ: ";
	while ( maxiQ.size() ) {
		cout << maxiQ.top() << ' ';
		maxiQ.pop();
	}
	cout << endl << "maxDeletedList: ";
	for ( auto mm: maxDeletedList ) {
		cout << mm.fi << ',' << mm.se << ' ';
	}
	cout << endl;
}

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int cases; cin >> cases;
	cout << linf << endl;

	for ( int i = 0; i < cases; i++ ) {
		cout << "*************************" << endl;
		maxQ = priority_queue<int>();
		minQ = priority_queue<int>();
		maxDeletedList.clear();
		minDeletedList.clear();
		int numberOfCommands; cin >> numberOfCommands;

		for ( int i = 0; i < numberOfCommands; i++ ) {
			Print();
			char command; cin >> command;
			int curNum; cin >> curNum;
			if ( command == 'I' ) {
				maxQ.push(curNum);
				minQ.push(curNum * -1);
				continue;
			}
			ll res = PopQueue(curNum);
			if ( res != linf ) {
				PushDeletedList(res, curNum * -1);
			}
		}
		Print();
		ll res1 = PopQueue(1);
		ll res2 = PopQueue(-1);
		if ( res1 == linf || res2 == linf ) {
			cout << "EMPTY" << endl;
			continue;
		}
		cout << res1 << ' ' << res2 << endl;
	}

    return 0;
}
