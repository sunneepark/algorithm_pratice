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

	if (idx.empty()) //접두사, 접미사가 없을 때
		return "";

	while (!idx.empty()) {
		cout << idx.top()<<" ";
		int camel_idx = str.find(str.substr(0, idx.top() + 1), 1); //접두사가 아니고 찾아보기
		cout << camel_idx << endl;

		if (camel_idx == len - idx.top() - 1 || camel_idx == -1) { //접미사 이거나 찾지 못했다면
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