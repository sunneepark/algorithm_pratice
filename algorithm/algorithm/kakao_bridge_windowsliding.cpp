#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
bool compare(int o1, int o2) {
	return o1 > o2; //왼쪽이 더 크게
}
int solution(vector<int> stones, int k) {
	int answer = 20000001;
	int max = 0;
	int maxIdx = 0;
	int i = 0;
	int curSize = 0;
	int removeIdx = 0;
	vector<int> window;
	vector<vector<int>::iterator> windowIt;

	while (i < stones.size()) {
		if (window.size() < k) {
			window.push_back(stones[i]);
			windowIt.push_back(window.end()-1);
			sort(window.begin(), window.end(), compare);
			i++;
		}
		if (window.size() == k) {
			window.erase(windowIt[removeIdx++]);
			window.push_back(stones[i]);
			windowIt.push_back(window.end() - 1);
			i++;
			sort(window.begin(), window.end(), compare);

			if (answer > window[0]) answer = window[0];
		}
	}
	for (int i = 0; i < stones.size() - k; i++) {
	}
	if (answer == 200000001) {
		for (int i = 0; i < stones.size(); i++) {
			if (max < stones[i]) {
				max = stones[i];
				maxIdx = i;
			}
		}
		answer = max;
	}
	return answer;
}
int main() {
	solution({ 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 }, 3);
}