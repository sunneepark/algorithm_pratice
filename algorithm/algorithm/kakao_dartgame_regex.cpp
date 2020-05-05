#include <string>
#include <regex>
#include <iostream>
using namespace std;

void split(string s) {
	std::regex re("[0-9]{1,2}[SDT][*#]?"); //���ڰ� 1�ڸ� Ȥ�� 2�ڸ� �� 0-99 ���� , ?�� null�� ����
	std::sregex_iterator next(s.begin(), s.end(), re);
	std::sregex_iterator end;
	while (next != end) {
		std::smatch match = *next;
		std::cout << match.str() << "\n";
		next++;
	}
}
int solution(string dartResult) {
	int answer = 0;
	//����ǥ�������� 
	split(dartResult);
	return answer;
}
int main() {
	solution("1D2S#10S");
}