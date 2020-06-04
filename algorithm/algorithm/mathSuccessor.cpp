#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	int sumS[3] = { 0 }; int sumIdx = -1;
	int two[4] = { 1,3,4,5 };
	int three[5] = { 3,1,2,4,5 };
	int twoIdx = -1;
	int threeIdx = -1;
	for (int i = 0; i < answers.size(); i++) {
		int answerTemp = answers.at(i);

		sumIdx = (++sumIdx) % 3;
		if ((i % 5) + 1 == answerTemp) sumS[sumIdx]++;

		++sumIdx;
		if (i % 2 == 0) {
			if (2 == answerTemp) sumS[sumIdx]++;
			threeIdx = ++threeIdx % 5;
		}
		else {
			twoIdx = (++twoIdx) % 4;
			if (two[twoIdx] == answerTemp) sumS[sumIdx]++;
		}

		++sumIdx;
		if (three[threeIdx] == answerTemp) sumS[sumIdx]++;
	}
	answer.push_back(1);
	if (sumS[answer.back() - 1] < sumS[1]) answer.pop_back();
	if (answer.empty() || sumS[answer.back() - 1] == sumS[1]) answer.push_back(2);

	while (!answer.empty() && sumS[answer.back() - 1] < sumS[2]) answer.pop_back();
	if (answer.empty() || sumS[answer.back() - 1] == sumS[2]) answer.push_back(3);
	return answer;
}

int main() {
	solution({ 1,2,3,4,5,3,1,2,4,5 });
}