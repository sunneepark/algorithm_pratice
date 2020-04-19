#include <iostream>
#include <string>
#include <stack>

using namespace std;
class node {
public:
	bool isNum;
	string data;
	node* left;
	node* right;

	node() {
		isNum = true;
		data = "";
		left = NULL;
		right = NULL;
	}
};

stack<double> s;
void calculator(char oper) {
	double second = s.top();
	s.pop();
	double first = s.top();
	s.pop();
	switch (oper)
	{
	case '+':
		s.push((double)first + second);
		break;
	case '-':
		s.push((double)first - second);
		break;
	case '*':
		s.push((double)first * second);
		break;
	case '/':
		s.push((double)first / second);
		break;
	default:
		break;
	}
}
void postorder(node* head) {
	if (head == NULL)
		return;

	postorder(head->left);
	postorder(head->right);
	
	if (head->isNum)
		s.push(stof(head->data, 0));
	else
		calculator((head->data).at(0));
}

int main() {
	int test_case;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int total = 0;
		cin >> total;
		cin.get();
		node* tree = new node[total+1];

		char str[15];
		for (int i = 0; i < total; i++) {
			*str = NULL;
			cin.getline(str, 15);

			char* context = NULL;
<<<<<<< HEAD
			//strtok_r in linux
=======
>>>>>>> 54526b59d182fb0492e00797d93408338c1fbdd2
			char* tok1 = strtok_s(str, " ", &context);
			tok1 = strtok_s(NULL, " ", &context);

			char *tok2;
			if ((tok2 = strtok_s(NULL, " ", &context)) != NULL) { //연산자 일 때
				tree[i + 1].isNum = false;
				tree[i + 1].data = tok1;
				tree[i + 1].left = &tree[stoi(tok2)];
				tree[i + 1].right = &tree[stoi(tok2 = strtok_s(NULL, " ", &context))];
			}
			else {
				tree[i + 1].data = tok1;
			}
		}
		postorder(&tree[1]);
		cout << "#" << test_case << " " << (int)s.top() << endl;
		
		s.pop();
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}