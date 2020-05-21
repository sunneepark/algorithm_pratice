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
	int parenNum[2] = { 0,0 }; //0 : ( , 1: ) 의 갯수
	for (char i : str) {
		if (i == '(') parenNum[0]++;
		else parenNum[1]++;
		if (parenNum[0] == parenNum[1]) return parenNum[0] * 2;
	}
}
void doReverse(string::iterator begin, string::iterator end) { // '(' 과 ')'의 위치 바꾸기
	while (begin != end) {
		if (*begin == '(') *begin = ')';
		else *begin = '(';
		begin++;
	}
}
string doRecursive(string str) { //1단계 + 2단계
	if (str == "") return ""; //step 1.빈 문자열인 경우 빈 문자열 반환
	
	int splitIdx = splitToUV(str);
	string u = str.substr(0, splitIdx);
	string v = str.substr(splitIdx, str.size() - splitIdx);
	cout << u << " " << v << endl;
	if (isCorrectStr(u)) { //올바른 괄호 문자열인 경우
		return u + doRecursive(v);
	}
	else { //올바른 괄호 문자열이 아닐 경우
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
	if (isCorrectStr(p)) return p; //이미 올바른 문자열 이면

	string answer = doRecursive(p);
	return answer;
}

int main() {
	cout << solution("()))((()");
	return 0;
}