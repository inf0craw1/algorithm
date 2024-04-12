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
struct Node {
	unordered_map<int, struct Node*> next;
	int num;
	int isEndOfNumber;
};
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
Node* GetNewNode(int n) {
	Node* newNode = new Node;
	newNode->num = n;
	newNode->isEndOfNumber = 0;
	return newNode;
}
Node* GetNextPos(Node* curNode, char t) {
	auto foundNode = curNode->next.find(t - '0');
	if ( foundNode != curNode->next.end() ) return foundNode->se;

	Node* newNode = GetNewNode(t - '0');
	curNode->next.insert(make_pair(t-'0', newNode));
	
	return newNode;
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);


	int cases; cin >> cases;

	for ( int z = 0; z < cases; z++ ) {

		Node* header = GetNewNode(0);

		int chk = 0;
		int numbers; cin >> numbers;

		for ( int i = 0; i < numbers; i++ ) {

			Node* curNode = header;
			string temp; cin >> temp;

			for ( auto t: temp ) {
				curNode = GetNextPos(curNode, t);
				if ( curNode->isEndOfNumber ) {
					chk = 1;
					break;
				}
			}
			if ( chk ) break;
			curNode->isEndOfNumber = 1;
		}
		
		cout << (chk ? "NO" : "YES") << endl;

	}

    return 0;
}
