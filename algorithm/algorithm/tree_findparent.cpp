#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n;
	cin >> n;

	int *tree = new int[n];
	fill_n(tree, n, 0);
	tree[0] = 1;

	stack<int> s;
	int p1, p2;
	for (auto i = 1; i < n; i++) {
		cin >> p1 >> p2;
		
		if (tree[p1-1] != 0) {
			tree[p2-1] = p1;
		}
		else if (tree[p2 - 1] != 0){
			tree[p1-1] = p2;
		}
		else {
			s.push(p1);
			s.push(p2);
		}

	}
	for (auto i = 1; i < n; i++)
		cout << tree[i] << endl;
	return 0;
}