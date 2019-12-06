#include <iostream>
#include <string>
#include <stack>

using namespace std;

string solution(string str) {
	
	int len = str.size();

	stack<int> idx;

	for (int i = 0; i < len - 1; i++) {
		if (str.substr(0, i+1) == str.substr(len - i - 1, len)) {
			cout << i << endl;
			idx.push(i);
		}
	}

	if (idx.empty()) //���λ�, ���̻簡 ���� ��
		return "";

	while (!idx.empty()) {
		cout << idx.top()<<" ";
		int camel_idx = str.find(str.substr(0, idx.top() + 1), 1); //���λ簡 �ƴϰ� ã�ƺ���
		cout << camel_idx << endl;

		if (camel_idx == len - idx.top() - 1 || camel_idx == -1) { //���̻� �̰ų� ã�� ���ߴٸ�
			idx.pop();
		}
		else {
			return str.substr(0, idx.top() + 1);
		}
	}

	return "";
}

int main() {
	string str = "";
	cin >> str;
	string ans;

	if ((ans = solution(str)) != "")
		cout << ans;
	else
		cout << "-1";
	return 0;
}