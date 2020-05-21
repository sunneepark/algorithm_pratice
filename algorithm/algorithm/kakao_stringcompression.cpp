#include <string>
#include <vector>
#include <iostream>
using namespace std;

int findDigitNum(int num) {
	if (num / 10 < 1) return 1;
	else return 1 + findDigitNum(num / 10);
}
int solution(string s) {
	int answer = s.size();

	for (int i = 1; i <= s.size() / 2; i++) { //size�� 2���� n/2����
		int temp = s.size();
		pair<string, int> prior("", 1);
		for (int j = 0; j+(2*i) <= s.size(); j += i) {
			string c1 = s.substr(j, i);
			string c2 = s.substr(j+i, i);

			if (c1 == c2) {
				if (prior.first == "" || prior.first == c1) {
					prior.first = c1; prior.second++;
				}
				else {
					int digitNum = findDigitNum(prior.second);
					temp -= ((prior.second)*i) - digitNum - i; //����ũ�� - �ߺ��ȼ�(�ڸ�) - ũ��
					prior = make_pair(c1, 2);
				}
			}
		}
		if (prior.first != "") {
			int digitNum = findDigitNum(prior.second);
			temp -= ((prior.second)*i) - digitNum - i; //����ũ�� - �ߺ��ȼ�(�ڸ�) - ũ��
		}

		if (answer > temp)
			answer = temp;
	}
	return answer;
}

int main() {
	cout << solution("abcabc") << endl;
}