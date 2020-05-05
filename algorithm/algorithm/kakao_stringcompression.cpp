#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

int findDigitNum(int num) {
	if (num / 10 < 1) return 1;
	else return 1 + findDigitNum(num / 10);
}
int solution(string s) {
	int answer = s.size();

	for (int i = 1; i <= s.size() / 2; i++) { //size가 2부터 n/2까지
		int temp = s.size();
		stack<string> storePrior;
		for (int j = 0; j+(2*i) <= s.size(); j += i) {
			string c1 = s.substr(j, i);
			string c2 = s.substr(j+i, i);

			if (c1 == c2) {
				if (storePrior.empty() || storePrior.top() == c1) storePrior.push(c1); //비었거나 이전이 같을때
				else { //새로 만들어야 할 때
					int digitNum = findDigitNum(storePrior.size()+1);
					//cout << storePrior.size()+1<<"digit" << digitNum << endl;
					temp -= ((storePrior.size() + 1)*i)-digitNum - i; //원래크기 - 중복된수(자리) - 크기
					while (!storePrior.empty()) storePrior.pop();
					storePrior.push(c1);
				}
				//cout << storePrior.top() << endl;
			}
		}
		if (!storePrior.empty()) {
			int digitNum = findDigitNum(storePrior.size() + 1);
			//cout << storePrior.size() + 1 << "digit" << digitNum << endl;
			temp -= ((storePrior.size() + 1) * i) - digitNum - i; //원래크기 - 중복된수(자리) - 크기
		}
	
		if (answer > temp)
			answer = temp;
	}
	return answer;
}

int main() {
	cout << solution("aaaaaaaaaaaaaaaa") << endl;
}