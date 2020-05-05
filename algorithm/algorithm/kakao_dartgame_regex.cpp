#include <string>
#include <regex>
#include <iostream>
using namespace std;

void split(string s) {
	std::regex re("[0-9]{1,2}[SDT][*#]?"); //숫자가 1자리 혹은 2자리 즉 0-99 까지 , ?는 null도 포함
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
	//정규표현식으로 
	split(dartResult);
	return answer;
}
int main() {
	solution("1D2S#10S");
}