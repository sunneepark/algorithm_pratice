#include <iostream>
#include <string>
using namespace std;


int solution(string dartResult) {
	int answer = 0;

	int *score = new int[3];
	int score_idx = -1;
	for (int i = 0; i < dartResult.length(); i++) {
		char ch = dartResult.at(i);

		if (ch >= '0' && ch <= '9') { //숫자인 경우
			if (dartResult.at(i + 1) == '0') {
				score[++score_idx] = 10;
				i++;
			}
			else
				score[++score_idx] = ch-'0';

			char bonus = dartResult.at(++i);
			switch (bonus) {
				case 'D':
					score[score_idx] = pow(score[score_idx], 2);
					break;
				case 'T':
					score[score_idx] = pow(score[score_idx], 3);
					break;
			}	
		}
		else if (ch == '#') {
			score[score_idx] = 0 - score[score_idx];
		}
		else if (ch == '*') {
			score[score_idx] *= 2;
			if(score_idx-1>=0)
				score[score_idx-1] *= 2;
		}

	}
	answer = score[0] + score[1] + score[2];
	return answer;
}

int main() {
	cout<<solution("1D2S#10S");
}