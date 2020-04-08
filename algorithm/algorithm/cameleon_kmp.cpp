#include <iostream>
#include <string>
#include <stack>

using namespace std;

string solution(string str) {

	int len = str.size();

	//kmp : 1. pi �迭 ����� 

	int j = 0;  //ã�� ���ڿ��� �ε���

	int *pi = new int[len]; //���λ����̻� �˷��ִ� �迭
	pi[0] = 0;
	for (int i = 1; i < len; i++) {
		while (j > 0 && str[i] != str[j]) {
			j = pi[j - 1];
		}
		if (str[i] == str[j])
			pi[i] = ++j;
		else
			pi[i] = 0;
	}

	j = pi[len - 1];

	if (j == 0)
		return "";
	for (int i = 1; i < len - 1; i++) {
		if (pi[i] == j) {
			return str.substr(0, j);
		}
	}

	j = pi[j - 1];
	return str.substr(0, j);

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