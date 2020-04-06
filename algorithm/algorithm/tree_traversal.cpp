#include <iostream>

using namespace std;

class Node {
private:
	char data;
	
public:
	Node* left;
	Node* right;
	
	Node() {
		this->data = NULL;
		this->left = NULL;
		this->right = NULL;
	}
	void setData(char data) {
		this->data = data;
	}
	char getData() {
		return data;
	}
};

void inorderTraversal(Node *temp) {
	if (!temp)
		return;
	cout << temp->getData();
	inorderTraversal(temp->left);
	inorderTraversal(temp->right);
}
void preorderTraversal(Node *temp) {
	if (!temp)
		return;
	preorderTraversal(temp->left);
	cout << temp->getData();
	preorderTraversal(temp->right);
}
void postTraversal(Node *temp) {
	if (!temp)
		return;
	postTraversal(temp->left);
	postTraversal(temp->right);
	cout << temp->getData();
}
int main() {
	int n = 0;//³ëµå °¹¼ö
	cin >> n;

	char data, left, right;

	Node *NodeTree = new Node[n];

	for (int i = 0; i < n; i++) {
		cin >> data >> left >> right;
		int idx = (int)(data - 'A');
		NodeTree[idx].setData(data);

		if (left != '.') {
			NodeTree[idx].left = &NodeTree[(int)(left-'A')];
		}

		if (right != '.') {
			NodeTree[idx].right = &NodeTree[(int)(right - 'A')];
		}

	}
	inorderTraversal(&NodeTree[0]);
	cout << endl;
	preorderTraversal(&NodeTree[0]);
	cout << endl;
	postTraversal(&NodeTree[0]);
	return 0;
}