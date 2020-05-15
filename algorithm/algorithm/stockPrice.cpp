#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer(prices.size(),0);
	stack<pair<int,int>> s;
	int idx = 0;

	for (; idx < prices.size()-1;idx++) {
		while (!s.empty() && s.top().second > prices[idx]) {
			int tempIdx = s.top().first;
			answer[tempIdx] = idx - tempIdx;
			s.pop();
		}
		s.push(make_pair(idx,prices[idx]));
	}
	while (!s.empty()) {
		int tempIdx = s.top().first;
		answer[tempIdx] = idx - tempIdx;
		s.pop();
	}
	return answer;
}
int main() {
	solution({ 1, 2, 3, 2, 3});
}