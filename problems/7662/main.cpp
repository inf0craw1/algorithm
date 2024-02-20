#include <bits/stdc++.h>

#define endl '\n'
#define linf 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
using namespace std;

typedef long long ll;

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
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

	int cases; cin >> cases;

	for ( int i = 0; i < cases; i++ ) {
		maxQ = priority_queue<int>();
		minQ = priority_queue<int>();
		maxDeletedList.clear();
		minDeletedList.clear();
		int numberOfCommands; cin >> numberOfCommands;

		for ( int i = 0; i < numberOfCommands; i++ ) {
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
