#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int solution(string arrangement) {
	int answer = 0;
	stack<int> s;

	for (int i = 0; i < arrangement.size(); i++) {
		if (arrangement[i] == '(')
			s.push(0);
		else {
			s.pop();
			if (arrangement[i - 1] == '(') { //·¹ÀÌÀú
				answer += s.size();
			}
			else {
				answer++;
			}
		}
	}
	return answer;
}
int main() {
	cout << solution("()(((()())(())()))(())");
	return 0;
}