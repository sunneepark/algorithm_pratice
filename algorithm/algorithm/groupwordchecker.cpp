#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string str) { //str이 그룹단어이면 1 반환
	bool pre_check[26] = { false };

	for (int i=0;i<str.size();i++){
		if (pre_check[str.at(i)-'a'])
			return 0;

		if (i!=str.size()-1 && str.at(i) != str.at(i + 1))
			pre_check[str.at(i)-'a'] = true;
	}
	return 1;
}
int main() {
	int n;
	cin >> n;

	stack<string> arr;
	string str;

	for (int i = 0; i < n; i++) {
		cin >> str;
		arr.push(str);
	}

	int check = 0;
	for (int i = 0; i < n; i++) {
		if (solution(arr.top()) == 1)
			check++;
		arr.pop();
	}
	cout << check;
	return 0;
}