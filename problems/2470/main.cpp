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

struct Node {
	Node* left;
	ll data;
	Node* right;
};

/* - GLOBAL VARIABLES ---------------------------- */
Node* rootNode = new Node;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
Node* GetNewNode(ll n) {
	Node* newNode = new Node;
	newNode->data = n;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
void InsertNode(Node* newNode) {
	Node* curNode = rootNode;
	
	while (1) {
		if ( newNode->data < curNode->data ) {
			if ( curNode->left == NULL ) {
				curNode->left = newNode;
				return;
			}
			curNode = curNode->left;
			continue;
		}
		if ( curNode->right == NULL ) {
			curNode->right = newNode;
			return;
		}
		curNode = curNode->right;
	}
}
void PrintTree(Node* curNode) {
	if ( curNode->left != NULL ) {
		PrintTree(curNode->left);
	}
	cout << curNode->data << ' ';
	if ( curNode->right != NULL ) {
		PrintTree(curNode->right);
	}
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int n, temp; cin >> n; 
	rootNode->data = 0;
	rootNode->left = NULL;
	rootNode->right = NULL;
	
	for ( int i = 0; i < n; i++ ) {
		cin >> temp;
		InsertNode(GetNewNode(temp));
	}
	PrintTree(rootNode);

	if ( rootNode->left == NULL ) {

	}
	if ( rootNode->right == NULL ) {

	}

	Node* leftNode = rootNode->left;
	Node* rightNode = rootNode->right;

	
	

    return 0;
}
