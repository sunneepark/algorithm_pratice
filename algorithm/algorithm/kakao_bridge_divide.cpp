#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int solution(vector<int> stones, int k) {
	int answer = 20000001;
	int max = 0;
	int maxIdx = 0;
	int i = 0;
	
	for (int i = 0; i < k; i++) { //맨 처음 넣기
		if (max < stones[i]) {
			max = stones[i];
			maxIdx = i;
		}
	}
	if (answer > max) answer = max;
	bool change = true;
	int changeCheckIdx = 0;
	for (int i = k; i < stones.size();i++) {
		if (maxIdx + k < i) {
			maxIdx = 0;
			max = 0;
			change = false;
			changeCheckIdx = i+k> stones.size() ? stones.size() : i + k;
		}
		if (changeCheckIdx == i) {
			change = true;
			if (change && answer > max) answer = max;
		}
		if (max < stones[i]) {
			max = stones[i];
			maxIdx = i;
			if (change && answer > max) answer = max;
		}
	}

	return answer;
}
int main() {
	solution({ 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 }, 3);
}