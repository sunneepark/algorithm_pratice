#include <iostream>
#include <string>

using namespace std;

void inOrder(char* tree, int idx, int end, string& answer) {
	if (idx > end)
		return;
	inOrder(tree, idx * 2, end, answer);
	answer += tree[idx];
	inOrder(tree, idx * 2 + 1, end, answer);
}
bool isValid(string answer) {
	bool isNum = false;
	for (int i = 0; i < answer.size(); i++) {
		if (!isNum) { //이전이 문자인데 
			if (answer.at(i) < '0' || answer.at(i) > '9') { //또 문자
				return false;
			}
			isNum = true;
		}
		else if (isNum) { //이전이 숫자인데 
			if (answer.at(i) >= '0' && answer.at(i) >= '9') { //또 숫자
				return false;
			}
			isNum = false;
		}
	}
	return true;
}
int main() {
	int test_case;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int total = 0;
		cin >> total;
		cin.get();

		char* tree = new char[total + 1];
		for (int i = 0; i < total; i++) {
			char str[15];
			cin.getline(str, 15);
			bool out = false;
			for (char c : str) {
				if (c == ' ') {
					out = !out;
				}
				else if (out) {
					tree[i + 1] = c;
					break;
				}
			}
		}
		string answer = "";
		inOrder(tree, 1, total, answer);
		cout << "#" << test_case << " " << isValid(answer) << endl;
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}