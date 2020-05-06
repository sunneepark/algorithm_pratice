#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

bool isCorrectStr(string str) {
	stack<char> s;
	for (char i : str) {
		if (i == '(') s.push(i);
		else {
			if (s.empty() || s.top() == ')') return false;
			else s.pop();
		}
	}
	if (s.empty()) return true;
	return false;
}
int splitToUV(string str) {
	int parenNum[2] = { 0,0 }; //0 : ( , 1: ) �� ����
	for (char i : str) {
		if (i == '(') parenNum[0]++;
		else parenNum[1]++;
		if (parenNum[0] == parenNum[1]) return parenNum[0] * 2;
	}
}
void doReverse(string::iterator begin, string::iterator end) { // '(' �� ')'�� ��ġ �ٲٱ�
	while (begin != end) {
		if (*begin == '(') *begin = ')';
		else *begin = '(';
		begin++;
	}
}
string doRecursive(string str) { //1�ܰ� + 2�ܰ�
	if (str == "") return ""; //step 1.�� ���ڿ��� ��� �� ���ڿ� ��ȯ
	
	int splitIdx = splitToUV(str);
	string u = str.substr(0, splitIdx);
	string v = str.substr(splitIdx, str.size() - splitIdx);
	cout << u << " " << v << endl;
	if (isCorrectStr(u)) { //�ùٸ� ��ȣ ���ڿ��� ���
		return u + doRecursive(v);
	}
	else { //�ùٸ� ��ȣ ���ڿ��� �ƴ� ���
		string vacant = "(";
		vacant += doRecursive(v);
		vacant += ")";
		u.erase(u.begin());
		u.erase(u.end()-1);
		doReverse(u.begin(), u.end());
		return vacant + u;
	}
}
string solution(string p) {
	if (isCorrectStr(p)) return p; //�̹� �ùٸ� ���ڿ� �̸�

	string answer = doRecursive(p);
	return answer;
}

int main() {
	cout << solution("()))((()");
	return 0;
}